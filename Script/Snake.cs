using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityStandardAssets.CrossPlatformInput;

public class Snake : MonoBehaviour {
    double Angle = 0f;//当前角度
    double tarAngle = 0f;
    int speed = 1;
    private Vector2 dir = Vector2.right;
   // private Vector2 movement = Vector2.right;

    //记录最后一个尾巴 s前的位置
    Vector2 pos;
    // Keep Track of Tail
    List<Transform> tail = new List<Transform>();
    List<Transform> Body = new List<Transform>();
    List<Vector2> posi = new List<Vector2>();
    //Queue posi = new Queue();
    // Did the snake eat something?
    bool ate = false;
    bool isLive = true;
    public GameObject PlayerTailPrefab;
    public GameObject BodyPrefab;
    const int disnub = 10;//一节身体移动到前一节的步数
    int mycount = disnub;//记录吃掉食物后5帧在长尾巴
    int eatsmafdcnt = 6;//每吃6个小点长一节尾巴

    //bool iszhuan = false;
    Quaternion targetRotation;
	// Use this for initialization
	void Start () {
        // Move the Snake every 300ms
        InvokeRepeating("Move", 0f, Time.deltaTime );
        //int len = (int)Random.Range(10, 20);
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
	}
	// Update is called once per frame
	void Update () {
        if (CrossPlatformInputManager.GetAxis("Horizontal")!=0 || CrossPlatformInputManager.GetAxis("Vertical")!=0)
        {
            float inputX = CrossPlatformInputManager.GetAxis("Horizontal");
            float inputY = CrossPlatformInputManager.GetAxis("Vertical") ;
            //Debug.Log("X:" + inputX + "   Y:" + inputY);
            double xy = System.Math.Sqrt(inputX * inputX + inputY * inputY);
            tarAngle = Mathf.Acos(inputX / (float)xy);
            tarAngle = (inputY > 0 ? tarAngle : -tarAngle) / Mathf.PI * 180f;//角度制
            //iszhuan = true;
        }
        phxz();
    }

    void Move()
    {
        if (!isLive) {
            dir = Vector2.zero;
        }
        Vector2 v = transform.position;
        transform.Translate(dir * Time.deltaTime * 5*speed);
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

    void phxz()
    {
        Angle = transform.GetComponent<Transform>().localEulerAngles.z;
        Angle = (Angle > 180 ? Angle - 360 : Angle);
        if (Angle != tarAngle)
        {
            targetRotation = Quaternion.Euler(0f, 0f, (float)tarAngle);
            transform.rotation = Quaternion.Slerp(transform.rotation, targetRotation, Time.deltaTime*3);
        }
    }
    void setSpeed()
    {
        speed = 2;
    }
    void Live()
    {
        if (!isLive)
        {
            transform.gameObject.SetActive(false);
            for (int i = 0; i < tail.Count; i++) {
                tail[i].gameObject.SetActive(false);
            }

            for (int i = 0; i < tail.Count; i+=2)
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
                    //Debug.Log("flag");
                    flag = true;
                    break;
                }
            }
            isLive = flag;
            Live();
        }
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
