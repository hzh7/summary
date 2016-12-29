/*
*该脚本主要功能是在游戏界面中显示玩家的当前长度和击杀数，以及排行榜信息
*/
using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System;

public class Leaderboard : MonoBehaviour
{
    int sco;
    int kil;
    string leader;
    GameObject script;
    public static bool has_limit;
    DateTime startTime;
    int count;
    void Start()
    {
        count = 0;
        startTime = DateTime.Now;
    }

    void OnGUI()
    {
        if (++count < 15) return;
        int w = Screen.width / 8;
        int h = Screen.height / 12;
        GUI.skin.label.normal.textColor = Color.red;
        GUI.skin.label.fontSize = w / 5;
        GUI.Label(new Rect(0, 0, w, h), "长度：" + getSco());
        GUI.Label(new Rect(0, h / 2, w, h), "杀击：" + getkil());

        GUI.skin.box.fontSize = (int)(5.8 * h / 12.2);
        GUI.skin.box.alignment = TextAnchor.MiddleCenter;
        GUI.Box(new Rect((int)(6.5 * w), 2, (int)(1.5 * w), h), "排行榜");

        GUI.skin.box.alignment = TextAnchor.UpperLeft;
        GUI.Box(new Rect((int)(6.5 * w), h + 4, (int)(1.5 * w), (int)(5.8 * h)), getTop10());
        if (has_limit)
        {
            GUI.skin.label.normal.textColor = Color.white;
            GUI.skin.label.fontSize = w / 3;
            GUI.Label(new Rect((int)(w * 3.5), 2, w * 8, (int)(1.2 * h)), getTime());
        }
    }

    public int getSco()
    {
        if (GameObject.Find("snakeHead") != null)
        {
            sco = GameObject.Find("snakeHead").GetComponent<Snake>().getScore();
        }
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

    public string getTop10()
    {
        leader = "";
        script = GameObject.Find("script");
        if (script == null) return "";
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
                leader += formate((i + 1), GameObject.Find("snakeHead").GetComponent<wenzi>().name, player_score);
                if (i != 9)
                    leader += "\n";
            }
            else
            {
                snakeAI tmp = snakeAIs[tops[i]].GetComponent<snakeAI>();
                leader += formate((i + 1), tmp.transform.GetComponent<AiName>().getName(), tmp.getScore());
                if (i != 9)
                    leader += "\n";
            }
        }
        return leader;
    }
    private String formate(int rank, String name, int score)
    {
        return String.Format(" {0,4} {1,-9} {2,3}", rank, name, score);
    }
    private String getTime()
    {
        long remains = 300 - (long)((DateTime.Now - startTime).TotalSeconds);
        if (remains == 0)
        {
            GameObject.Find("snakeHead").GetComponent<Snake>().isLive = false;
            GameObject.Find("snakeHead").GetComponent<Snake>().Live();
            has_limit = false;
        }
        return String.Format("0{0}:{1:00}", remains / 60, remains % 60);
    }
}
