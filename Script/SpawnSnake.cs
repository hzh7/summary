using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
public class SpawnSnake : MonoBehaviour
{
    public static SpawnSnake Instance;

    public GameObject SnakePrefab;
    public GameObject TailPrefab;

    List<Transform> snakeAI = new List<Transform>();
    //she数量
    public int snakeCount = 1;
    // Borders
    public Transform borderTop;
    public Transform borderBottom;
    public Transform borderLeft;
    public Transform borderRight;

    void Awake()
    {
        // Register the singleton
        if (Instance != null)
        {
            Debug.LogError("Multiple instances of SpecialEffectsHelper!");
        }
        Instance = this;
    }

    // Use this for initialization
    void Start()
    {
        for (int i = 0; i < snakeCount; i++)
        {
            GameObject g = Spawn();
            snakeAI.Insert(0, g.transform);
        }
    }

    void Update()
    {
        
    }
    public int getsnakeCount()
    {
        return snakeCount;
    }
    public void setsnakeCount()
    {
        snakeCount -= 1;
    }
    // Spawn one piece of food
    GameObject Spawn()
    {
        // x position between left & right border
        int x = (int)Random.Range(borderLeft.position.x,
                                  borderRight.position.x);

        // y position between top & bottom border
        int y = (int)Random.Range(borderBottom.position.y,
                                  borderTop.position.y);

        // Instantiate the food at (x, y)
        GameObject Gobj = (GameObject)Instantiate(SnakePrefab,
                    new Vector2(x, y),
                    Quaternion.identity); // default rotation
        return Gobj;
    }

}