using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
public class Snake : MonoBehaviour {
    //public static Snake Itself;
    // Current Movement Direction
    // (by default it moves to the right)
    private Vector2 dir;
    //public Vector2 speed = new Vector2(0.01f, 0.01f);
    // 1 - Store the movement
    private Vector2 movement = Vector2.right;

    //记录最后一个尾巴 s前的位置
    Vector2 pos;
    // Keep Track of Tail
    List<Transform> tail = new List<Transform>();

    // Did the snake eat something?
    bool ate = false;

    // Did the snake is live?
    bool isLive = true;

    // Tail Prefab
    public GameObject TailPrefab;

	// Use this for initialization
	void Start () {
        // Move the Snake every 300ms
        InvokeRepeating("Move", 0.3f, 0.3f);
        int len = (int)Random.Range(4, 9);
        for (int i = 0; i < len; i++)
        {
            //
            //Invoke("Move", 2);
        }
        
	}
	
	// Update is called once per frame
	void Update () {
        // Move in a new Direction?
        /*if (Input.GetKey(KeyCode.RightArrow))
            dir = Vector2.right;
        else if (Input.GetKey(KeyCode.DownArrow))
            dir = -Vector2.up;    // '-up' means 'down'
        else if (Input.GetKey(KeyCode.LeftArrow))
            dir = -Vector2.right; // '-right' means 'left'
        else if (Input.GetKey(KeyCode.UpArrow))
            dir = Vector2.up;*/
        if(Input.GetKey(KeyCode.LeftArrow)||Input.GetKey(KeyCode.RightArrow)||
            Input.GetKey(KeyCode.UpArrow) || Input.GetKey(KeyCode.DownArrow))
        {

            float inputX = Input.GetAxis("Horizontal");
            float inputY = Input.GetAxis("Vertical");
            double xy = System.Math.Sqrt(inputX * inputX + inputY * inputY);
            movement = new Vector2(inputX / (float)xy, inputY / (float)xy);
        }
        /************************************/
        dir = movement;
        dir = dir * 0.1f;
        // Save current position (gap will be here)
        Vector2 v = transform.position;
        // Move head into new direction
        transform.Translate(dir);

        // Ate something? Then insert new Element into gap
        if (ate)
        {
            // Load Prefab into the world
            GameObject g = (GameObject)Instantiate(TailPrefab, Move(), Quaternion.identity);

            // Keep track of it in our tail list
            tail.Insert(0, g.transform);
            
                
            //Invoke("Move", 0.3f);

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

    Vector2 Move()// 记录最后一个尾巴0.3s前的位置
    {
        if (tail.Count == 0)
            pos = transform.position;
        else
        {
            pos = tail[tail.Count - 1].position;
        }
        return pos;
    }

    void Live()
    {
        if (!isLive)
        {
            Debug.Log("goto gameover");
            Application.LoadLevel("gameover");
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
            Debug.Log("frame");
            isLive = false;
            Live();
        }
        // Collided with Tail or Border
        else
        {
            // ToDo 'You lose' screen
        }
    }

}
