/*
*该脚本主要实现给每个AI蛇随机生成一个名字，
*该名字会显示在该蛇的头上方，并且名字会用于排行榜中的信息显示
*/using UnityEngine;
using System.Collections;
using System;

public class AiName : MonoBehaviour {
    private Camera camera;
    private string Ainame;
    GameObject hero;
    float npcHeight;
    private static int nameIndex = 0;
    private static string[] names;

    void Start()
    {
        hero = this.gameObject;
        camera = Camera.main;
        LoadPlayerNameText();
        Ainame = getRandomName();
        float scal_y = transform.localScale.y;
        npcHeight = scal_y;
    }

    public static void LoadPlayerNameText()
    {
        TextAsset namesAsset = (TextAsset)Resources.Load("name", typeof(TextAsset));
        if (namesAsset.text != null && namesAsset.text.Length > 0)
        {
            string content = namesAsset.text;
            names = content.Split(new string[] { "\n" }, StringSplitOptions.RemoveEmptyEntries); 
        }
    }
    public string getName()
    {
        return this.Ainame;
    }

    public static string getRandomName()
    {
        if (names != null)
        {
            nameIndex = UnityEngine.Random.Range(0, names.Length);
        }
        string playerName = "";
        if (nameIndex >= 0)
        {
            playerName = names[nameIndex];
        }
        return playerName;
    }

    void OnGUI()
    {
        Vector3 worldPosition = new Vector3(transform.position.x, transform.position.y + npcHeight, transform.position.z);
        Vector2 position = camera.WorldToScreenPoint(worldPosition);
        position = new Vector2(position.x, Screen.height - position.y);
        Vector2 nameSize = GUI.skin.label.CalcSize(new GUIContent(this.Ainame));
        GUI.color = Color.red;
        GUI.skin.label.fontSize = 16;
        GUI.Label(new Rect(position.x - (nameSize.x / 2), position.y - nameSize.y, nameSize.x, nameSize.y), Ainame);
    } 
}
