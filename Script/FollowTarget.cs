/*using UnityEngine;
using System.Collections;

public class FollowTarget : MonoBehaviour
{

    public Vector3 offset;
    private Transform playerBip;
    public float smoothing = 1;

    // Use this for initialization
    void Start()
    {
        playerBip = GameObject.FindGameObjectWithTag("Player").transform.Find("Role");
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        //transform.position = playerBip.position + offset;
        Vector3 targetPos = playerBip.position + offset;
        transform.position = Vector3.Lerp(transform.position, targetPos, smoothing * Time.deltaTime);
    }
}*/
using UnityEngine;
using System.Collections;

public class FollowTarget: MonoBehaviour
{

    public Transform character;   //摄像机要跟随的人物
    public float smoothTime = 0.01f;  //摄像机平滑移动的时间
    private Vector3 cameraVelocity = Vector3.zero;
    public Camera mainCamera;  //主摄像机（有时候会在工程中有多个摄像机，但是只能有一个主摄像机吧）

    void Awake()
    {
        mainCamera = Camera.main;
    }

    void Update()
    {
        transform.position = Vector3.SmoothDamp(transform.position, character.position + new Vector3(0, 0, -5), ref cameraVelocity, smoothTime);
    }

}