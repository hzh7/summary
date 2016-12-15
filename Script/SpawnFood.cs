using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class SpawnFood : MonoBehaviour
{
    public static SpawnFood Instance;

    // Food Prefab
    public GameObject foodPrefab;
    List<Transform> food = new List<Transform>();
    //食物数量
    public int foodCount = 500;
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
        for (int i = 0; i < foodCount; i++)
        {
            Spawn();
        }
    }

    void Update()
    {        
        if (food.Count < foodCount)
        {
            Spawn();
        }
    }
    public int getFoodCount()
    {
        return food.Count;
    }
    public void setFoodCount(Transform a)
    {
        food.Remove(a);
    }

    void Spawn()
    {
        float x = (float)Random.Range(borderLeft.position.x,
                                  borderRight.position.x);
        float y = (float)Random.Range(borderBottom.position.y,
                                  borderTop.position.y);
        GameObject Gobj = (GameObject)Instantiate(foodPrefab,
                    new Vector2(x, y), Quaternion.identity);
        Gobj.GetComponent<Renderer>().material.color = RandomColor();
        food.Insert(0, Gobj.transform);
    }
    public void Spawn(Vector2 p)
    {
        GameObject Gobj = (GameObject)Instantiate(foodPrefab,
                    p, Quaternion.identity);
        Gobj.GetComponent<Renderer>().material.color = RandomColor();
        food.Insert(0, Gobj.transform);
    }

    Color RandomColor()
    {
        //随机颜色的RGB值。即刻得到一个随机的颜色
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