﻿using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityStandardAssets.CrossPlatformInput;

public class Snake : MonoBehaviour {
    public static Snake InstanceSnake;
    Transform myTransform;
    double Angle = 0f;//当前角度
    double tarAngle = 0f;
    private Vector2 dir = Vector2.right;
    List<Transform> tail = new List<Transform>();
    List<Transform> Body = new List<Transform>();
    List<Vector2> posi = new List<Vector2>();
    int score = 0;
    int killnub = 0;
    bool ate = false;
    bool isLive = true;
    public GameObject PlayerTailPrefab;
    public GameObject BodyPrefab;
    int disnub = 10;//一节身体移动到前一节的步数
    int mycount = 10;//记录吃掉食物后5帧在长尾巴
    int eatsmafdcnt = 0;//每吃6个小点长一节尾巴
    int yanshi = 30;//用于加速延迟拉屎
    bool enChuan = true;
    Quaternion targetRotation;

    //move里用到的变量
    Vector2 mv;
    Vector2 mp;
    GameObject mg;

    void Awake()
    {
        // Register the singleton
        if (InstanceSnake != null)
        {
            Debug.LogError("Multiple instances of SpecialEffectsHelper!");
        }
        InstanceSnake = this;
        myTransform = transform;
    }
	void Start () {
        InvokeRepeating("Move", 0f, Time.deltaTime );
        int len = 4;
        for (int i = 0; i < len; i++)
        {
            Vector2 p = new Vector2(myTransform.position.x-(i+1)*1f, myTransform.position.y);
            GameObject g = (GameObject)Instantiate(PlayerTailPrefab, p, Quaternion.identity);
            tail.Insert(i, g.transform);
        }
        for (int i = 0; i < len * disnub + 1; i++)
        {
            Vector2 p = new Vector2(myTransform.position.x - i * 1 / (float)disnub, myTransform.position.y);
            posi.Add(p);
        }
        //Collider2D[] hitColliders = Physics2D.OverlapCircleAll(transform.position, 0.5f);
        //Debug.Log("hitColliders" + hitColliders);
	}
	void Update () {
        //Angle = transform.GetComponent<Transform>().localEulerAngles.z;
        Angle = myTransform.localEulerAngles.z;
        Angle = (Angle > 180 ? Angle - 360 : Angle);
        if (Angle != tarAngle)
        {
            targetRotation = Quaternion.Euler(0f, 0f, (float)tarAngle);
            myTransform.rotation = Quaternion.Slerp(myTransform.rotation, targetRotation, Time.deltaTime *5);
        }
        score = tail.Count * 6 + eatsmafdcnt;
        myTransform.localScale = new Vector3(tail.Count * 0.001f + 0.5f, tail.Count * 0.001f + 0.5f, 1f);
        for (int i = 0; i < tail.Count; i++)
        {
            tail[i].transform.localScale = myTransform.localScale;
        }
        /*if (!isLive)
        {
            CancelInvoke("Move");dir = Vector2.zero;
            Debug.Log("ccccc");
        }*/
        
    }
    public int getScore()
    {
        return score;
    }
    public int getKillnub()
    {
        return killnub;
    }
    void Move()
    {
        myTransform.Translate(dir * Time.deltaTime * 5);
        if (ate)
        {
            posi.Insert(0, myTransform.position);
            mycount--;
            if (mycount == 0)
            {
                mp = posi[posi.Count - 1];
                mg = (GameObject)Instantiate(PlayerTailPrefab, mp, Quaternion.identity);
                tail.Insert(tail.Count - 1, mg.transform);
                ate = false;
                mycount = disnub;
            }
            for (int i = 0; i < tail.Count; i++)
            {
                tail[i].position = posi[(i + 1) * disnub];
            }
        }
        else if (tail.Count > 0)
        {
            posi.Insert(0, myTransform.position);
            for (int i = 0; i < tail.Count; i++)
            {
                tail[i].position = posi[(i + 1) * disnub];
            }
            posi.RemoveAt(posi.Count - 1);
        }
    }
    public void KillSnake()
    {
        killnub++;
    }
    public void JoyStickControlMove(Vector2 direction)
    {
        float inputX = direction.x;
        float inputY = direction.y;
        double xy = System.Math.Sqrt(inputX * inputX + inputY * inputY);
        tarAngle = Mathf.Acos(inputX / (float)xy);
        tarAngle = (inputY > 0 ? tarAngle : -tarAngle) / Mathf.PI * 180f;
    }
    public void ButtonControlPressed()
    {
        if (isLive && score > 24)//实现加速拉屎，身体变短
        {
            if (yanshi > 0)
            {
                yanshi--;
            }
            else if (eatsmafdcnt > 0)
            {
                eatsmafdcnt--;
                yanshi = 30;
                SpawnFood.Instance.Spawn(tail[tail.Count - 1].transform.position);
            }
            else
            {
                Destroy(tail[tail.Count - 1].gameObject);
                tail.Remove(tail[tail.Count-1]);
                eatsmafdcnt = 6;
            }
            Move();
        }
    }
    void Live()
    {
        if (!isLive)
        {
            GameObject.Find("script").GetComponent<UDPsocket>().Main();
            CancelInvoke("Move");
            dir = Vector2.zero; 
            transform.gameObject.SetActive(false);
            for (int i = 0; i < tail.Count; i++) {
                Destroy(tail[i].gameObject);
                //tail[i].gameObject.SetActive(false);
            }

            for (int i = 0; i < tail.Count; i++)
            {
                Vector2 v = tail[i].position;
                v.x += Random.Range(-0.5f, 0.5f);
                v.y += Random.Range(-0.5f, 0.5f);
                GameObject g = SpawnBody(v);
                Body.Insert(0, g.transform);
            }
            var gameOver = FindObjectOfType<GameOver>();
            gameOver.ShowButtons();
            gameOver.ShowImage();
        }
    }
    
    void OnTriggerEnter2D(Collider2D coll)
    {
        if (coll.name.StartsWith("FoodPrefab"))
        {
            eatsmafdcnt++;
            Destroy(coll.gameObject);
            SpawnFood.Instance.setFoodCount(coll.gameObject.transform);
            if (eatsmafdcnt == 6)
            {
                ate = true;
                eatsmafdcnt = 0;
            }
        }
        if (coll.name.StartsWith("BodyPrefab"))
        {
            Destroy(coll.gameObject);
            ate = true;
        }
        if (coll.name.StartsWith("borderTop") || coll.name.StartsWith("borderBottom") ||
            coll.name.StartsWith("borderLeft") || coll.name.StartsWith("borderRight")) //|| coll.name.StartsWith("TailPrefab(Clone)")
        {
            isLive = false;
            Live();
        }
        if (coll.name.StartsWith("chuansongmenPrefab"))
        {
            if (enChuan)
            {
                enChuan = false;
                Vector2 v = GameObject.Find("script").GetComponent<CsDoor>().ChuanSong(coll);
                transform.position = v;
            }
            else
            {
                enChuan = true;
            }
        }
        if (coll.name.StartsWith("TailPrefab"))
        {
            bool flag = false;
            for (int i = 0; i < tail.Count; i++)
            {
                if (coll.transform == tail[i])
                {
                    flag = true;
                    break;
                }
            }
            isLive = flag;
            Live();
        }
    }
    GameObject SpawnBody(Vector2 v)
    {
       GameObject Gobj = (GameObject)Instantiate(BodyPrefab, v,
                    Quaternion.identity); 
        //Gobj.GetComponent<Renderer>().material.color = Color.green;
        return Gobj;
    }
}
