﻿using UnityEngine;
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
            GameObject g = Spawn();
            food.Insert(0, g.transform);
        }
    }

    void Update()
    {        
        if (food.Count < foodCount)
        {
            GameObject g = Spawn();
            food.Insert(0, g.transform); 
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
    // Spawn one piece of food
    GameObject Spawn()
    {
        // x position between left & right border
        float x = (float)Random.Range(borderLeft.position.x,
                                  borderRight.position.x);

        // y position between top & bottom border
        float y = (float)Random.Range(borderBottom.position.y,
                                  borderTop.position.y);

        // Instantiate the food at (x, y)
        GameObject Gobj = (GameObject)Instantiate(foodPrefab,
                    new Vector2(x, y),
                    Quaternion.identity); // default rotation
        Gobj.GetComponent<Renderer>().material.color = RandomColor(); 
       // Gobj.Renderer.material.color = Color.red;
        return Gobj;
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