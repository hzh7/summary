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
    public static int foodSub = 5;
    public int foodCount = 0;
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
        for (int i = 0; i < foodSub; i++)
        {
            GameObject g = Spawn();
            food.Insert(0, g.transform);
            foodCount += 1; 
        }
        /*if (foodCount < 5)
        {
            GameObject g = Spawn();
            food.Insert(0, g.transform);
            foodCount++;
        }*/
    }

    void Update()
    {        
        if (foodCount < foodSub)
        {
            GameObject g = Spawn();
            food.Insert(0, g.transform); 
            foodCount++;
        }
    }
    public int getFoodCount()
    {
        return foodCount;
    }
    public void setFoodCount()
    {
        //Debug.Log("remove count");
        foodCount -= 1;
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
        GameObject Gobj = (GameObject)Instantiate(foodPrefab,
                    new Vector2(x, y),
                    Quaternion.identity); // default rotation
        return Gobj;
    }

}