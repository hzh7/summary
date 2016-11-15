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
    float angle = Random.RandomRange(0, 2 * Mathf.PI);
    // Keep Track of Tail
    List<Transform> tail = new List<Transform>();

    // Did the snake eat something?
    bool ate = false;

    // Tail Prefab
    public GameObject TailPrefab;

    //private int enemyState;
    //获取要追踪的对象
    private GameObject playe0;
    private GameObject playe1;
    private GameObject playe2;
    private GameObject playe3;
    private GameObject playe4;

    //敌人的巡逻范围
    public const int AI_ATTACK_DISTANCE = 5;
    public bool isHatred = false;

    // Use this for initialization
    void Start()
    {
        dir = new Vector2(Mathf.Cos(angle), Mathf.Sin(angle));
        //Debug.LogError(dir.ToString("f3"));
        // Move the Snake every 300ms
        InvokeRepeating("Move", 0.3f, 0.3f);
        int len = (int)Random.Range(4, 9);
        for (int i = 0; i < len; i++)
        {
            GameObject g = (GameObject)Instantiate(TailPrefab, transform.position, Quaternion.identity);
            tail.Insert(0, g.transform);
        }
        playe0 = GameObject.Find("snakeHead");
        playe1 = GameObject.Find("SnakePrefab(Clone)");
    }

    // Update is called once per frame
    void Update()
    {
       /* // Move in a new Direction?
        if (Input.GetKey(KeyCode.RightArrow))
            dir = Vector2.right;
        else if (Input.GetKey(KeyCode.DownArrow))
            dir = -Vector2.up;    // '-up' means 'down'
        else if (Input.GetKey(KeyCode.LeftArrow))
            dir = -Vector2.right; // '-right' means 'left'
        else if (Input.GetKey(KeyCode.UpArrow))
            dir = Vector2.up;*/
        

        if (Vector2.Distance(transform.position,playe0.transform.position) < AI_ATTACK_DISTANCE)
        {
            //angle = Random.RandomRange(0, 2 * Mathf.PI);
            dir = -dir;
            //dir = new Vector2(Mathf.Cos(angle), Mathf.Sin(angle));
            //Debug.Log("bianhua dir");
        }
        if (Vector2.Distance(transform.position, playe1.transform.position) < AI_ATTACK_DISTANCE/* &&
            Vector2.Distance(transform.position, playe1.transform.position)!=0*/)
        {
            float dangerAngle = angle;
            angle = Random.RandomRange(-dangerAngle - 1, -dangerAngle + 1);
            dir = new Vector2(Mathf.Cos(angle), Mathf.Sin(angle));
            //dir = new Vector2(Mathf.Cos(angle), Mathf.Sin(angle));
            //Debug.Log("AI快要撞到AL");
        }
        
        /*Vector2.Distance(transform.position, playe1.transform.position) < 10 ||
            Vector2.Distance(transform.position, playe2.transform.position) < 10 ||
            Vector2.Distance(transform.position, playe3.transform.position) < 10 ||
            Vector2.Distance(transform.position, playe4.transform.position) < 10 */
        if (transform.position.x < 10 || transform.position.x > 190 || 
            transform.position.y < 10 || transform.position.y > 90)
        {
            Debug.Log("AI快要撞到frame");
            float dangerAngle = angle;
            angle = Random.RandomRange(-dangerAngle - 1, -dangerAngle + 1);
            dir = new Vector2(Mathf.Cos(angle), Mathf.Sin(angle));
        }
        if (!isLive)
        {
            dir = Vector2.zero;
        }
    }

    /*void newDir()
    {
        Debug.Log("do newdir");
        dir = new Vector2(Mathf.Cos(angle), Mathf.Sin(angle));
    }*/

    void Move()
    {
        //dir = Random.insideUnitCircle;
        // Save current position (gap will be here)
        Vector2 v = transform.position;
        // Debug.Log("move");
        // Move head into new direction
        transform.Translate(dir);

        // Ate something? Then insert new Element into gap
        if (ate)
        {
            // Load Prefab into the world
            GameObject g = (GameObject)Instantiate(TailPrefab, v, Quaternion.identity);

            // Keep track of it in our tail list
            tail.Insert(0, g.transform);

            // Reset the flag
            ate = false;
        }
        // Do we have a Tail?
        else if (tail.Count > 0)
        {
            // Move last Tail Element to where the Head was
            tail.Last().position = v;

            // Add to front of list, remove from the back
            tail.Insert(0, tail.Last());
            tail.RemoveAt(tail.Count - 1);
        }
    }

    void OnTriggerEnter2D(Collider2D coll)
    {
        // Food?
        if (coll.name.StartsWith("FoodPrefab"))
        {
            // Get longer in next Move call
            ate = true;
            //SpawnFood.foodCount--;
            //Debug.Log("撞到食物");
            // Remove the Food
            Destroy(coll.gameObject);

            SpawnFood.Instance.setFoodCount();
        }
        if (coll.name.StartsWith("borderTop") || coll.name.StartsWith("borderBottom") ||
        coll.name.StartsWith("borderLeft") || coll.name.StartsWith("borderRight"))
        {
            //Debug.Log("撞到frame");
            isLive = false;
        }
        // Collided with Tail or Border
        else
        {
            // ToDo 'You lose' screen
        }
    }

}
