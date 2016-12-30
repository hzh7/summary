using UnityEngine;
using System.Collections;

public class menuscript : MonoBehaviour
{

    public void StartLimitGame()
    {
        // "Stage1" is the name of the first scene we created.
        Leaderboard.has_limit = true;
        Application.LoadLevel("newSnake");
    }
    public void StartGame()
    {
        // "Stage1" is the name of the first scene we created.
        Leaderboard.has_limit = false;
        Application.LoadLevel("newSnake");
    }
    void Update()
    {
        if (Input.GetKey(KeyCode.Escape))
        {
            Application.Quit();
        }
    }
}