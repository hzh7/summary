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
    public int snakeCount = 10;
    public Transform borderTop;
    public Transform borderBottom;
    public Transform borderLeft;
    public Transform borderRight;

    void Awake()
    {
        if (Instance != null)
        {
            Debug.LogError("Multiple instances of SpecialEffectsHelper!");
        }
        Instance = this;
    }

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
        if (snakeAI.Count < snakeCount)
        {
            GameObject g = Spawn();
            snakeAI.Insert(0, g.transform);
        }
    }
    public int getSnakeCount()
    {
        return snakeCount;
    }
    public void setSnakeCount(Transform a)
    {
        snakeAI.Remove(a);
    }
    GameObject Spawn()
    {
        int x = (int)Random.Range(borderLeft.position.x+10,
                                  borderRight.position.x-10);
        int y = (int)Random.Range(borderBottom.position.y+10,
                                  borderTop.position.y-10);
        GameObject Gobj = (GameObject)Instantiate(SnakePrefab,
                    new Vector2(x, y),Quaternion.identity); 
        return Gobj;
    }
}