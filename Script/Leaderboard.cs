using UnityEngine;
using System.Collections;


/*主界面的排行榜*/
public class Leaderboard : MonoBehaviour {
    int sco;
    int kil;
    void Start()
    {
        
    }
    void OnGUI()
    {
        GUI.Label(new Rect(0, 0, 1000, 100), "长度：" + getSco());
        GUI.Label(new Rect(0, 20, 1000, 100), "杀击：" + getkil());
        GUI.skin.label.normal.textColor = Color.red;
    }
    int getSco()
    {
        if(GameObject.Find("snakeHead") != null){
            sco = GameObject.Find("snakeHead").GetComponent<Snake>().getScore();
        }
        //Debug.Log("sce: " + sco);
        return sco;
    }
    int getkil()
    {
        if (GameObject.Find("snakeHead") != null)
        {
            kil = GameObject.Find("snakeHead").GetComponent<Snake>().getKillnub();
        }
        return kil;
    }
}
