using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
public class snakeAI : MonoBehaviour
{
    // Current Movement Direction
    // (by default it moves to the right)
    Vector2 dir;
    // Did the snake is live?
    bool isLive = true;
    float angle;
    // Keep Track of Tail
    List<Transform> tail = new List<Transform>();

    // Did the snake eat something?
    bool ate = false;
    Vector2 dangerdir = Vector2.zero;   
    // Tail Prefab
    public GameObject TailPrefab;

    //private int enemyState;
    //获取要追踪的对象
    private GameObject playe0;
    private GameObject[] playe1;
    private GameObject playe2;
    private GameObject playe3;
    private GameObject go;

    //敌人的巡逻范围
    public const int AI_ATTACK_DISTANCE = 5;
    public bool isHatred = false;

    // Use this for initialization
    void Start()
    {
        angle = Random.RandomRange(0, 2 * Mathf.PI);
        dir = new Vector2(Mathf.Cos(angle), Mathf.Sin(angle));
        //Debug.LogError(dir.ToString("f3"));
        // Move the Snake every 300ms
        InvokeRepeating("Move", 0.3f, 0.03f);
        int len = (int)Random.Range(9, 20);
        for (int i = 0; i < len; i++)
        {
            GameObject g = (GameObject)Instantiate(TailPrefab, transform.position, Quaternion.identity);
            tail.Insert(0, g.transform);
        }
        //playe0 = GameObject.Find("snakeHead");
        playe0 = GameObject.FindGameObjectWithTag("Player");
    }

    // Update is called once per frame
    void Update()
    {
        
        go = GameObject.FindGameObjectWithTag("SnakeAI");
        if (!isLive)
        {
            dir = Vector2.zero;
        }
    }
    void Move()
    {
        
        if (playe0 !=null && Vector2.Distance(transform.position, playe0.transform.position) < AI_ATTACK_DISTANCE)
        {
           /* if (dangerdir == Vector2.zero)
            {
                dangerdir = -dir;
                dir = dangerdir;
            }*/
            dir = (transform.position - playe0.transform.position) / Vector2.Distance(transform.position, playe0.transform.position);
            Debug.Log("AI和蛇很近");
        }
        //GameObject go;
        /*foreach (GameObject go in playe1) 
        {
            if (Vector2.Distance(transform.position, go.transform.position) < AI_ATTACK_DISTANCE &&
                Vector2.Distance(transform.position, go.transform.position) > 0)
            {
                Debug.Log("AI快要撞到AL"); 
                if (dangerdir == Vector2.zero)
                {
                    dangerdir = -dir;
                    dir = dangerdir;
                }
            }
        }*/
        if (Vector2.Distance(transform.position, go.transform.position) < AI_ATTACK_DISTANCE &&
                Vector2.Distance(transform.position, go.transform.position) > 0)
        {
            Debug.Log("AI快要撞到AL");
            if (dangerdir == Vector2.zero)
            {
                dangerdir = -dir;
                dir = dangerdir;
            }
        }

        if (transform.position.x < 10 || transform.position.x > 190 ||
            transform.position.y < 10 || transform.position.y > 90)
        {
           // Debug.Log("AI快要撞到frame");
            if (dangerdir == Vector2.zero)
            {
                dangerdir = -dir;
                dir = dangerdir;
            }
            //dir = new Vector2(Mathf.Cos(angle), Mathf.Sin(angle));
        }
        else
        {
            if (Random.Range(0, 100) >= 90)
            {
                angle += Random.Range(-90, 90)/180f*Mathf.PI;
                dir = new Vector2(Mathf.Cos(angle), Mathf.Sin(angle));
            }
        }
        Vector2 v = transform.position;
        transform.Translate(dir*0.1f);

        if (ate)
        {
            GameObject g = (GameObject)Instantiate(TailPrefab, v, Quaternion.identity);
            tail.Insert(0, g.transform);
            ate = false;
        }
        else if (tail.Count > 0)
        {
            tail.Last().position = v;
            tail.Insert(0, tail.Last());
            tail.RemoveAt(tail.Count - 1);
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
            //SpawnSnake.Instance.setSnakeCount();
        }
    }

    void OnTriggerEnter2D(Collider2D coll)
    {
        // Food?
        if (coll.name.StartsWith("FoodPrefab"))
        {
            ate = true;
            Destroy(coll.gameObject);
            SpawnFood.Instance.setFoodCount(coll.gameObject.transform);
        }
        if (coll.name.StartsWith("borderTop") || coll.name.StartsWith("borderBottom") ||
        coll.name.StartsWith("borderLeft") || coll.name.StartsWith("borderRight") )
        {
            //Debug.Log("撞到frame");
            isLive = false;
            SpawnSnake.Instance.setSnakeCount(coll.gameObject.transform);
            Live();
        }
    }

}
