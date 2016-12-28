using UnityEngine;
using System.Collections;

public class sound : MonoBehaviour {
    //用于控制声音的AudioSource组件
    private AudioSource _audioSource;
    bool islive =true;
    void Awake()
    {
        _audioSource = transform.GetComponent<AudioSource>();
        // _audioSource = gameObject.AddComponent<AudioSource>();
    }

    void Update()
    {
        //Debug.Log(getlive());
        //Debug.Log(_audioSource);
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
