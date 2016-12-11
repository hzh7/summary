using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityStandardAssets.CrossPlatformInput;

public class Snake : MonoBehaviour {
    public static Snake InstanceSnake;
    double Angle = 0f;//当前角度
    double tarAngle = 0f;
    int speed = 5;
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

    
    Quaternion targetRotation;

    void Awake()
    {
        // Register the singleton
        if (InstanceSnake != null)
        {
            Debug.LogError("Multiple instances of SpecialEffectsHelper!");
        }
        InstanceSnake = this;
    }
	void Start () {
        InvokeRepeating("Move", 0f, Time.deltaTime );
        int len = 4;
        for (int i = 0; i < len; i++)
        {
            Vector2 p = new Vector2(transform.position.x-(i+1)*1f, transform.position.y);
            GameObject g = (GameObject)Instantiate(PlayerTailPrefab, p, Quaternion.identity);
            tail.Insert(i, g.transform);
        }
        for (int i = 0; i < len * disnub + 1; i++)
        {
            Vector2 p = new Vector2(transform.position.x - i * 1 / (float)disnub, transform.position.y);
            posi.Add(p);
        }
        //Collider2D[] hitColliders = Physics2D.OverlapCircleAll(transform.position, 0.5f);
        //Debug.Log("hitColliders" + hitColliders);
	}
	void Update () {
        Angle = transform.GetComponent<Transform>().localEulerAngles.z;
        Angle = (Angle > 180 ? Angle - 360 : Angle);
        if (Angle != tarAngle)
        {
            targetRotation = Quaternion.Euler(0f, 0f, (float)tarAngle);
            transform.rotation = Quaternion.Slerp(transform.rotation, targetRotation, Time.deltaTime * 3);
        }
        score = tail.Count * 6 + eatsmafdcnt;
        transform.localScale = new Vector3(tail.Count * 0.001f + 0.4f, tail.Count * 0.001f + 0.4f, 1f);
        for (int i = 0; i < tail.Count; i++)
        {
            tail[i].transform.localScale = transform.localScale;
        }
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
        if (!isLive) {
            dir = Vector2.zero;
        }
        Vector2 v = transform.position;
        transform.Translate(dir * Time.deltaTime * speed);
        if (ate)
        {
            posi.Insert(0, transform.position);
            mycount--;
            if (mycount == 0)
            {
                Vector2 p = posi[posi.Count - 1];
                GameObject g = (GameObject)Instantiate(PlayerTailPrefab, p, Quaternion.identity);
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
    public void KillSnake()
    {
        killnub++;
    }
    public void JoyStickControlMove(Vector2 direction)
    {
        //Debug.Log("direction.x  " + direction.x + "   direction.y" + direction.y);
        float inputX = direction.x;
        float inputY = direction.y;
        double xy = System.Math.Sqrt(inputX * inputX + inputY * inputY);
        tarAngle = Mathf.Acos(inputX / (float)xy);
        tarAngle = (inputY > 0 ? tarAngle : -tarAngle) / Mathf.PI * 180f;
    }
    public void ButtonControlPressed()
    {
        Move();
        //Move();
    }
    void Live()
    {
        if (!isLive)
        {
            GameObject.Find("script").GetComponent<UDPsocket>().Main();

            transform.gameObject.SetActive(false);
            for (int i = 0; i < tail.Count; i++) {
                tail[i].gameObject.SetActive(false);
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
