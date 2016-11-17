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
    List<Transform> Body = new List<Transform>();
    // Did the snake eat something?
    bool ate = false;

    // Did the snake is live?
    bool isLive = true;

    // PlayerTail Prefab
    public GameObject PlayerTailPrefab;
    public GameObject BodyPrefab;
	// Use this for initialization
	void Start () {
        // Move the Snake every 300ms
        InvokeRepeating("Move", 0.3f, Time.deltaTime );
        int len = (int)Random.Range(10, 20);
        for (int i = 0; i < len; i++)
        {
            Vector2 p = new Vector2(transform.position.x-(i+1)*1f, transform.position.y);
            GameObject g = (GameObject)Instantiate(PlayerTailPrefab, p, Quaternion.identity);
            tail.Insert(i, g.transform);
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
        //Debug.Log("angle:" + Angle);
        dir = movement;

        /************************************/

        //Debug.LogError("pause");
    }

    void Move()
    {
        if (!isLive) {
            dir = Vector2.zero;
        }
        Vector2 v = transform.position;
        transform.Translate(dir*Time.deltaTime*3 );

        // Ate something? Then insert new Element into gap
        if (ate)
        {
            // Load Prefab into the world
            GameObject g = (GameObject)Instantiate(PlayerTailPrefab, v, Quaternion.identity);
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
            //Destroy(transform.gameObject);
            transform.gameObject.SetActive(false);
            for (int i = 0; i < tail.Count; i++) {
                tail[i].gameObject.SetActive(false);
            }

            for (int i = 0; i < tail.Count; i+=10)
            {
                Vector2 v = tail[i].position;
                GameObject g = SpawnBody(v);
                Body.Insert(0, g.transform);
            }

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
            Destroy(coll.gameObject);
            SpawnFood.Instance.setFoodCount(coll.gameObject.transform);
        }
        if (coll.name.StartsWith("borderTop") || coll.name.StartsWith("borderBottom") ||
            coll.name.StartsWith("borderLeft") || coll.name.StartsWith("borderRight")) //|| coll.name.StartsWith("TailPrefab(Clone)")
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
    GameObject SpawnBody(Vector2 v)
    {
       GameObject Gobj = (GameObject)Instantiate(BodyPrefab, v,
                    Quaternion.identity); 
        //Gobj.GetComponent<Renderer>().material.color = RandomColor();
        return Gobj;
    }
}
