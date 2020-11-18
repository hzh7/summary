/*
*该脚本同为游戏的核心脚本，用于控制AI蛇的运动，吃食物，
*身体变长和死亡等一系列动作
*/
using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
public class snakeAI : MonoBehaviour
{
    Transform myTransform;
    Vector2 dir = Vector2.right;
    bool isLive = true;
    float Angle = 0f;//当前角度
    double tarAngle = 0f;
    Color[] color = new Color[2];
    int chColor = 0;
    int score = 0;
    List<Transform> tail = new List<Transform>();
    List<Transform> Body = new List<Transform>();
    List<Vector2> posi = new List<Vector2>();
    bool ate = false;
    Vector2 dangerdir = Vector2.zero;   
    public GameObject TailPrefab;
    public GameObject BodyPrefab;
    const int disnub = 10;//一节身体移动到前一节的步数
    int mycount = disnub;//记录吃掉食物后5帧在长尾巴
    private GameObject playe0;
    private GameObject[] playe1;
    bool dange = false;
    int eatsmafdcnt = 6;//每吃6个小点长一节尾巴
    public bool isHatred = false;
    bool iszhuan = false;
    Quaternion targetRotation;
    bool enChuan = true;

    //move用到的变量
    Vector2 mv;
    Vector2 mp;
    GameObject mg;

    void Awake()
    {
        myTransform = transform;
    }
    void Start()
    {
        color[0] = RandomColor();
        color[1] = RandomColor();
        InvokeRepeating("Move", 0f, Time.deltaTime);
        InvokeRepeating("Changedirection", 0f, Time.deltaTime * 10);
        int len = (int)Random.Range(3, 6);
        for (int i = 0; i < len; i++)
        {
            Vector2 p = new Vector2(myTransform.position.x - (i + 1) * 1f, myTransform.position.y);
            GameObject g = (GameObject)Instantiate(TailPrefab, p, Quaternion.identity);
            //Debug.Log(tail.Count);
            g.GetComponent<Renderer>().material.color = color[tail.Count % 2];
            tail.Add(g.transform);
        }
        for (int i = 0; i < len * disnub + 1; i++)
        {
            Vector2 p = new Vector2(myTransform.position.x - i * 1 / (float)disnub, myTransform.position.y);
            posi.Add(p);
        }
        //Collider2D hitColliders = Physics2D.OverlapCircle(transform.position, 5f);
    }

    void Update()
    {
        if (!isLive)
        {
            dir = Vector2.zero;
        }
        Angle = myTransform.localEulerAngles.z;
        Angle = (Angle > 180 ? Angle - 360 : Angle);
        if (Angle != tarAngle)
        {
            targetRotation = Quaternion.Euler(0f, 0f, (float)tarAngle);
            myTransform.rotation = Quaternion.Slerp(myTransform.rotation, targetRotation, Time.deltaTime * 5);
        }
        score = tail.Count * 6 + eatsmafdcnt;
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
                mg = (GameObject)Instantiate(TailPrefab, mp, Quaternion.identity);
                mg.GetComponent<Renderer>().material.color = color[tail.Count % 2];
                tail.Add(mg.transform);
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

    public int getScore()
    {
        
        return score;
    }

    void Changedirection()
    {        
        if (transform.position.x < 10 )
        {
            tarAngle = 10;
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
        Gobj.GetComponent<Renderer>().material.color = color[score % 2];
        return Gobj;
    }

    Color RandomColor()
    {
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
