/*
*该脚本主要实现对背景音乐的控制
*/
using UnityEngine;
using System.Collections;

public class sound : MonoBehaviour {
    private AudioSource _audioSource;
    bool islive =true;
    void Awake()
    {
        _audioSource = transform.GetComponent<AudioSource>();
    }

    void Update()
    {
        if (!getlive())
        {
            _audioSource.Stop();
        }
    }
    public bool getlive()
    {
        if (GameObject.Find("snakeHead") == null)
        {
            islive = false;
        }
        return islive;
    }
}
