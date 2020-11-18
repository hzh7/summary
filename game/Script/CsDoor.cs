/*
*该脚本主要实现传送门的生成和位置的随机变化
*/
using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class CsDoor : MonoBehaviour {
    public GameObject chuansongmenPrefab;
    List<Transform> Doors = new List<Transform>();
    public int DoorCount = 10;

    public Transform borderTop;
    public Transform borderBottom;
    public Transform borderLeft;
    public Transform borderRight;
    int i;
    Vector2 v;
    void Start () {
        InvokeRepeating("Changedoor", 1f, Time.deltaTime * 50);
        for (int i = 0; i < DoorCount; i++)
        {
            SpawnDoor();
        }
    }
	
    public Vector2 ChuanSong(Collider2D coll)
    {
        while (true)
        {
            int i = Random.Range(0, Doors.Count);
            if (coll.transform != Doors[i])
            {
                Vector2 dis = Doors[i].position;
                return dis;
            }
        }
    }
	void Changedoor() {
        i = Random.Range(0, Doors.Count);
        float x = (float)Random.Range(borderLeft.position.x + 5,
                                  borderRight.position.x - 5);
        float y = (float)Random.Range(borderBottom.position.y + 5,
                                  borderTop.position.y - 5);
        v = new Vector2(x, y);
        Doors[i].transform.position = v;
    }
    void SpawnDoor()
    {
        float x = (float)Random.Range(borderLeft.position.x+5,
                                  borderRight.position.x-5);
        float y = (float)Random.Range(borderBottom.position.y+5,
                                  borderTop.position.y-5);
        GameObject Gobj = (GameObject)Instantiate(chuansongmenPrefab,
                    new Vector2(x, y), Quaternion.identity);
        Doors.Insert(0, Gobj.transform);
    }
}
