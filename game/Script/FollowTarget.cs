using UnityEngine;
using System.Collections;

public class FollowTarget: MonoBehaviour
{

    public Transform character;   //摄像机要跟随的人物
    public float smoothTime = 0.01f;  //摄像机平滑移动的时间
    private Vector3 cameraVelocity = Vector3.zero;
    public Camera mainCamera;  //主摄像机（有时候会在工程中有多个摄像机，但是只能有一个主摄像机吧）
    float size = 10;

    void Awake()
    {
        mainCamera = Camera.main;
    }
    void Start()
    {
        InvokeRepeating("CameSize", 0f, Time.deltaTime*10);
    }
    void Update()
    {
        //mainCamera.orthographicSize = 50f;
        transform.position = Vector3.SmoothDamp(transform.position, character.position + new Vector3(0, 0, -5), ref cameraVelocity, smoothTime);
    }
    void CameSize()
    {
        if (GameObject.Find("snakeHead") != null)
        {
            size = GameObject.Find("snakeHead").GetComponent<Snake>().getScore();
        }
        mainCamera.orthographicSize = size*0.01f + 10;
    }
}