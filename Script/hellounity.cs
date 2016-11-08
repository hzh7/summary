using UnityEngine;
using System.Collections;

public class hellounity : MonoBehaviour {
    int count = 1;
	// Use this for initialization
	void Start () {
       /* print("hello unity");
        Debug.Log("hello");*/
	}
	
	// Update is called once per frame
	void Update () {
        if (count < 200)
        {
            Debug.Log("hello");
            count++;
        }
        else
        {
            Debug.LogError("error");
        }
	}
}
