using UnityEngine;
using System.Collections;
using System;

public class AiName : MonoBehaviour {

    //主摄像机对象  
    private Camera camera;
    //NPC名称  
    private string Ainame;

    //主角对象  
    GameObject hero;
    //NPC模型高度  
    float npcHeight;
    private static int nameIndex = 0;
    private static string[] names;
    //private static System.Random nameRandom;



    void Start()
    {
        //得到主角对象  
        hero = this.gameObject;
        //得到摄像机对象  
        camera = Camera.main;
        LoadPlayerNameText();
        Ainame = getRandomName();
        //得到模型原始高度  
        //float size_y = collider.bounds.size.y;
        //得到模型缩放比例  
        float scal_y = transform.localScale.y;
        //它们的乘积就是高度  
        npcHeight = scal_y;

    }

    public static void LoadPlayerNameText()
    {
        //从Resource读取txt文件，文件格式为utf-8（中文）
        TextAsset namesAsset = (TextAsset)Resources.Load("name", typeof(TextAsset));
        if (namesAsset.text != null && namesAsset.text.Length > 0)
        {
            string content = namesAsset.text;
            //names = content.Split(); //忽略空行
            names = content.Split(new string[] { "\n" }, StringSplitOptions.RemoveEmptyEntries); //忽略空行
        }

        /*if (names != null && names.Length > 0)
        {
            nameRandom = new System.Random();
        }*/
        //Debug.Log("namerandom: "+names[1]);
    }
    public string getName()
    {
        return this.Ainame;
    }
    //获取随机名
    public static string getRandomName()
    {
        if (names != null)
        {
            nameIndex = UnityEngine.Random.Range(0, names.Length);
        }
        string playerName = "";
        //Debug.Log("pn: "+playerName);
        if (nameIndex >= 0)
        {
            playerName = names[nameIndex];
        }
        //Debug.Log(playerName);
        return playerName;
    }
    void OnGUI()
    {
        Vector3 worldPosition = new Vector3(transform.position.x, transform.position.y + npcHeight, transform.position.z);
        //根据NPC头顶的3D坐标换算成它在2D屏幕中的坐标  
        Vector2 position = camera.WorldToScreenPoint(worldPosition);
        //得到真实NPC头顶的2D坐标  
        position = new Vector2(position.x, Screen.height - position.y);

        //计算NPC名称的宽高  
        Vector2 nameSize = GUI.skin.label.CalcSize(new GUIContent(this.Ainame));
        //根据tag设置显示颜色  
        if (this.tag == "green")
            GUI.color = Color.green;
        else if (this.tag == "red")
            GUI.color = Color.red;
        GUI.skin.label.fontSize = 16;//字体大小  
        //绘制NPC名称  
        GUI.Label(new Rect(position.x - (nameSize.x / 2), position.y - nameSize.y, nameSize.x, nameSize.y), Ainame);
    } 
}
