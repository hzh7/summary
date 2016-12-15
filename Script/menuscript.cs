using UnityEngine;
using System.Collections;

public class menuscript : MonoBehaviour {

    public void StartGame()
    {
        // "Stage1" is the name of the first scene we created.
        Application.LoadLevel("newSnake");
    }
}

