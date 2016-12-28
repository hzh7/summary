using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System;

/*主界面的排行榜*/
public class Leaderboard : MonoBehaviour {
    int sco;
    int kil;
    string leader;
    GameObject script;
    void Start()
    {
    }
    void OnGUI()
    {
        /******{*******/
        int w = Screen.width / 8;
        int h = Screen.height / 12;
        GUI.skin.label.normal.textColor = Color.red;
        GUI.skin.label.fontSize = w / 5;
        GUI.Label(new Rect(0, 0, w, h), "长度：" + getSco());
        GUI.Label(new Rect(0, h/2, w, h), "杀击：" + getkil());
        //GUIStyle style = new GUIStyle(GUI.skin.box);
        //GUI.skin.box.alignment = TextAnchor.MiddleCenter;
        GUI.skin.box.fontSize = w / 5;
        GUI.skin.box.alignment = TextAnchor.MiddleCenter;
        GUI.Box(new Rect(7 * w, 2, w, h), "排行榜");
        GUI.skin.box.alignment = TextAnchor.UpperLeft;
        GUI.Box(new Rect(7 * w, h + 4, w, 6 * h), getTop10());
        /******}*******/
        //Debug.Log("border:" + GUI.skin.box.border);
    }
    public int getSco()
    {
        if(GameObject.Find("snakeHead") != null){
            sco = GameObject.Find("snakeHead").GetComponent<Snake>().getScore();
        }
        //Debug.Log("sce: " + sco);
        return sco;
    }
    public int getkil()
    {
        if (GameObject.Find("snakeHead") != null)
        {
            kil = GameObject.Find("snakeHead").GetComponent<Snake>().getKillnub();
        }
        return kil;
    }
    /**************/
    public string getTop10()
    {
        leader = "";
        script = GameObject.Find("script");
        if (script == null) return "";
        //Debug.Log(snakeAIs.GetComponent<SpawnSnake>().hi());
        List<Transform> snakeAIs = script.GetComponent<SpawnSnake>().getSnakeAIs();
        int[] top10 = new int[10];
        int[] scores = new int[snakeAIs.Count];
        int j = 0;
        int min_pos = 0;
        for (int i = 0; i < snakeAIs.Count; ++i)
            scores[i] = snakeAIs[i].GetComponent<snakeAI>().getScore();
        for (int i = 0; i < snakeAIs.Count; ++i)
        {
            if (j < 10)
            {
                top10[j] = i;
                ++j;
                if (scores[i] < scores[top10[min_pos]]) min_pos = i;
            }
            else
            {
                if (scores[i] < scores[top10[min_pos]])
                {
                    top10[min_pos] = i;
                    for (int k = 0; k < 10; ++k)
                        if (scores[top10[k]] < scores[top10[min_pos]]) min_pos = k;
                }
            }
            //Debug.Log(snakeAIs[i].GetComponent<snakeAI>().getScore());
        }
        if (GameObject.Find("snakeHead") == null) return "";
        Snake player = GameObject.Find("snakeHead").GetComponent<Snake>();
        int player_score = 0;
        if (player != null)
            player_score = player.getScore();
        List<int> tops = new List<int>(top10);
        tops.Sort((x, y) => {
            if (scores[x] > scores[y]) return -1;
            else if (scores[x] == scores[y]) return 0;
            else return 1;
        });
        int player_pos = 11;
        int m = 9;
        while (m >= 0 && scores[tops[m]] < player_score)
        {
            player_pos = m;
            --m;
            if (m > 0) tops[m + 1] = tops[m];
        }
        ++m;
        for (int i = 0; i < 10; ++i)
        {
            if (i == m)
            {
                leader += (i + 1) + " " + GameObject.Find("snakeHead").GetComponent<wenzi>().name + " " + player_score + "\n";
            }
            else
            {
                snakeAI tmp = snakeAIs[tops[i]].GetComponent<snakeAI>();
                leader += (i + 1) + " " + tmp.transform.GetComponent<AiName>().getName() + " " + tmp.getScore() + "\n";
            }
        }
        return leader;
    }
}
