/*
*该脚本主要实现AI蛇的动态生成，并可控制当前游戏中AI蛇的数量
*/
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
    public Sprite[] textures;
    int texturenub = 1;

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
        textures = Resources.LoadAll<Sprite>("skin");
        texturenub = Random.Range(0, textures.Length);
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

    public List<Transform> getSnakeAIs()
    {
        return snakeAI;
    }

    GameObject Spawn()
    {
        int x = (int)Random.Range(borderLeft.position.x+10,
                                  borderRight.position.x-10);
        int y = (int)Random.Range(borderBottom.position.y+10,
                                  borderTop.position.y-10);
        GameObject Gobj = (GameObject)Instantiate(SnakePrefab,
                    new Vector2(x, y),Quaternion.identity);
        Gobj.GetComponent<SpriteRenderer>().sprite = textures[texturenub];
        return Gobj;
    }
}