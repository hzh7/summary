﻿using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
public class snakeAI : MonoBehaviour
{
    int snakeID;
    Vector2 dir = Vector2.right;
    bool isLive = true;
    float Angle = 0f;//当前角度
    double tarAngle = 0f;
    Color color;
    List<Transform> tail = new List<Transform>();
    List<Transform> Body = new List<Transform>();
    List<Vector2> posi = new List<Vector2>();
    // Did the snake eat something?
    bool ate = false;
    Vector2 dangerdir = Vector2.zero;   
    // Tail Prefab
    public GameObject TailPrefab;
    public GameObject BodyPrefab;
    const int disnub = 10;//一节身体移动到前一节的步数
    int mycount = disnub;//记录吃掉食物后5帧在长尾巴
    //private int enemyState;
    //获取要追踪的对象
    private GameObject playe0;
    private GameObject[] playe1;
    //private GameObject playe2;
    //private GameObject playe3;
    private GameObject go;
    bool dange = false;
    int eatsmafdcnt = 6;//每吃6个小点长一节尾巴
    //敌人的巡逻范围
    public const float AI_ATTACK_DISTANCE = 5f;
    public bool isHatred = false;
    bool iszhuan = false;
    Quaternion targetRotation;
    void Start()
    {
        //dir = new Vector2(Mathf.Cos(Angle), Mathf.Sin(Angle));
        color = RandomColor();

        InvokeRepeating("Move", 0f, Time.deltaTime);
        InvokeRepeating("Changedirection", 0f, Time.deltaTime * 10);
        int len = (int)Random.Range(3, 6);
        for (int i = 0; i < len; i++)
        {
            Vector2 p = new Vector2(transform.position.x - (i + 1) * 1f, transform.position.y);
            GameObject g = (GameObject)Instantiate(TailPrefab, p, Quaternion.identity);
            g.GetComponent<Renderer>().material.color = color;
            tail.Insert(i, g.transform);
        }
        for (int i = 0; i < len * disnub + 1; i++)
        {
            Vector2 p = new Vector2(transform.position.x - i * 1 / (float)disnub, transform.position.y);
            posi.Add(p);
        }
        /*Collider2D hitColliders = Physics2D.OverlapCircle(transform.position, 5f);
        Debug.Log("hitColliders" + hitColliders);*/
         
        //playe0 = GameObject.FindGameObjectWithTag("Player"); playe1 = GameObject.FindGameObjectsWithTag("TailPrefab(Clone)");
    }

    void Update()
    {
        
        if (!isLive)
        {
            dir = Vector2.zero;
        }
        Angle = transform.GetComponent<Transform>().localEulerAngles.z;
        Angle = (Angle > 180 ? Angle - 360 : Angle);
        if (Angle != tarAngle)
        {
            targetRotation = Quaternion.Euler(0f, 0f, (float)tarAngle);
            transform.rotation = Quaternion.Slerp(transform.rotation, targetRotation, Time.deltaTime * 3);
        }
    }
    void Move()
    {
        Vector2 v = transform.position;
        transform.Translate(dir * Time.deltaTime * 5);
        if (ate)
        {
            posi.Insert(0, transform.position);
            mycount--;
            if (mycount == 0)
            {
                Vector2 p = posi[posi.Count - 1];
                GameObject g = (GameObject)Instantiate(TailPrefab, p, Quaternion.identity);
                g.GetComponent<Renderer>().material.color = color;
                tail.Insert(tail.Count - 1, g.transform);
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
            posi.Insert(0, transform.position);
            for (int i = 0; i < tail.Count; i++)
            {
                tail[i].position = posi[(i + 1) * disnub];
            }
            posi.RemoveAt(posi.Count - 1);
        }
    }

    void Changedirection()
    {
        /*if (playe0 != null && Vector2.Distance(transform.position, playe0.transform.position) < AI_ATTACK_DISTANCE)
        {
            tarAngle += Vector2.Angle(transform.position, playe0.transform.position);
            Debug.Log("AI和蛇很近");
            Debug.Log(Vector2.Angle(transform.position, playe0.transform.position));
        }
        //GameObject go;
        foreach (GameObject go in playe1) 
        {
            if (Vector2.Distance(transform.position, go.transform.position) < AI_ATTACK_DISTANCE &&
                Vector2.Distance(transform.position, go.transform.position) > 0)
            {
                Debug.Log("AI快要撞到AL");
                tarAngle += Vector2.Angle(transform.position, go.transform.position);
            }
        }*/
        
        //Debug.Log("hit   "+hitColliders);
        
        if (transform.position.x < 10 )
        {
            //Debug.Log("transform.position.x" + transform.position.x + "    tarAanle" + tarAngle);
            tarAngle = 10;
            //Debug.Log("  after  tarAanle" + tarAngle);

        } 
        if ( transform.position.x > 190 )
        {
            tarAngle = 160;

        } 
        if (transform.position.y < 10 )
        {
            tarAngle = 100;

        } 
        if (transform.position.y > 90)
        {
            tarAngle = -80;

        }
        else
        {
            if (Random.Range(0, 100) >= 80)
            {
                tarAngle += Random.Range(-90, 90);
            }
        }
    }
    void Live()
    {
        if (!isLive)
        {
            Destroy(transform.gameObject);
            for (int i = 0; i < tail.Count; i++)
            {
                Destroy(tail[i].gameObject);
            }
            for (int i = 0; i < tail.Count; i++)
            {
                Vector2 v = tail[i].position;
                v.x += Random.Range(-0.5f,0.5f);
                v.y += Random.Range(-0.5f, 0.5f);
                GameObject g = SpawnBody(v);
                Body.Insert(0, g.transform);
            }
        }
    }

    void OnTriggerEnter2D(Collider2D coll)
    {
        if (coll.name.StartsWith("FoodPrefab"))
        {
            eatsmafdcnt--;
            Destroy(coll.gameObject);
            SpawnFood.Instance.setFoodCount(coll.gameObject.transform);
            if (eatsmafdcnt == 0)
            {
                ate = true;
                eatsmafdcnt = 6;
            }
        }
        if (coll.name.StartsWith("BodyPrefab"))
        {
            Destroy(coll.gameObject);
            ate = true;
        }

        if (coll.name.StartsWith("TailPrefab"))
        {
            bool flag = false;
            for(int i=0;i<tail.Count;i++){
                if (coll.transform == tail[i])
                {
                    flag = true;
                    break;
                }
            }
            isLive = flag;
            if (!isLive)
            {
                SpawnSnake.Instance.setSnakeCount(transform);
            }
            Live();
        }
        if (coll.name.StartsWith("PlayerTailPrefab"))
        {
            Snake.InstanceSnake.KillSnake();
            isLive = false;
            SpawnSnake.Instance.setSnakeCount(transform);
            Live();
        }

        if (coll.name.StartsWith("borderTop") || coll.name.StartsWith("borderBottom") ||
        coll.name.StartsWith("borderLeft") || coll.name.StartsWith("borderRight") )
        {
            Debug.Log("撞到frame");
            isLive = false;
            SpawnSnake.Instance.setSnakeCount(transform);
            Live();
        }
    }

    GameObject SpawnBody(Vector2 v)
    {
        GameObject Gobj = (GameObject)Instantiate(BodyPrefab, v,
                     Quaternion.identity);
        Gobj.GetComponent<Renderer>().material.color = color;
        return Gobj;
    }

    Color RandomColor()
    {
        //随机颜色的RGB值。即刻得到一个随机的颜色
        List<Color> co = new List<Color>();
        co.Insert(0, Color.blue);
        co.Insert(0, Color.cyan);
        co.Insert(0, Color.green);
        co.Insert(0, Color.red);
        co.Insert(0, Color.yellow);
        int index = Random.Range(0, 5);
        return co[index];
    }
}
