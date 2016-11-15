using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityStandardAssets.CrossPlatformInput;

public class Snake : MonoBehaviour {
    double Angle = 0f;//当前角度
    private Vector2 dir;
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
            Vector2 p = new Vector2(transform.position.x-(i+1)*1f, transform.position.y);
            GameObject g = (GameObject)Instantiate(TailPrefab, p, Quaternion.identity);
            tail.Insert(i, g.transform);
            Debug.Log(tail[i].position.x);
        }
        var moveJoystick = FindObjectOfType<Joystick>();
	}
	// Update is called once per frame
	void Update () {
        if (CrossPlatformInputManager.GetAxis("Horizontal")!=0 || CrossPlatformInputManager.GetAxis("Vertical")!=0)
        {

            float inputX = CrossPlatformInputManager.GetAxis("Horizontal");
            float inputY = CrossPlatformInputManager.GetAxis("Vertical");
            double xy = System.Math.Sqrt(inputX * inputX + inputY * inputY);
            movement = new Vector2(inputX / (float)xy, inputY / (float)xy);
            Angle = Mathf.Acos(inputX / (float)xy) / System.Math.PI*180;
        }
        Debug.Log("angle:" + Angle);


        /************************************/
        dir = movement;
        // Save current position (gap will be here)
        Vector2 v = transform.position;
        // Move head into new direction
        //Debug.Log(dir);
        transform.Translate(dir * Time.deltaTime * 5);
        //transform.Rotate(0, 0, (float)Angle, Space.World);
        tail[0].transform.parent = transform;
        tail[1].transform.parent = tail[0].transform;
        tail[2].transform.parent = tail[1].transform;   
        // Ate something? Then insert new Element into gap
        if (ate)
        {
            GameObject g = (GameObject)Instantiate(TailPrefab, Move(), Quaternion.identity);
            tail.Insert(tail.Count-1, g.transform);
            ate = false;
        }
        else if (tail.Count > 0)
        {
            /*tail.Last().position = v;
            // Add to front of list, remove from the back
            tail.Insert(0, tail.Last());
            tail.RemoveAt(tail.Count - 1);*/
            /*for (int i = tail.Count - 1; i > 0; i--)
            {
                /*tail[i].transform.position =new
                    Vector2(Mathf.MoveTowards(tail[i].transform.position.x, tail[i - 1].transform.position.x,
                    Time.deltaTime),
                    Mathf.MoveTowards(tail[i].transform.position.y, tail[i - 1].transform.position.y, 
                    Time.deltaTime));
                float inputX = tail[i - 1].transform.position.x - tail[i].transform.position.x;
                float inputY = tail[i - 1].transform.position.y - tail[i].transform.position.y;
                double xy = System.Math.Sqrt(inputX * inputX + inputY * inputY);
                Vector2 diri = new Vector2(inputX / (float)xy, inputY / (float)xy);
                tail[i].transform.Translate(diri * 0.05f);
                Debug.Log(("diri * Time.deltaTime * 5:") + diri * 0.05f);
            }
            float X = transform.position.x - tail[0].transform.position.x;
            float Y = transform.position.y - tail[0].transform.position.y;
            double xy1 = System.Math.Sqrt(X * X + Y * Y);
            Vector2 dirii = new Vector2(X / (float)xy1, Y / (float)xy1);
            tail[0].Translate(dirii * 0.05f);*/

        }
        Debug.LogError("pause");
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
            //Destroy(transform.gameObject);
            transform.gameObject.SetActive(false);
            var gameOver = FindObjectOfType<GameOver>();
            gameOver.ShowButtons();
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
