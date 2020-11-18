using UnityEngine;
using System.Collections;

public class wenzi : MonoBehaviour {
    private Camera camera;
    public string name;
    float npcHeight;
    
    void Start()
    {
        camera = Camera.main;
        name = "Player";
        npcHeight = transform.localScale.y;
    }

    void OnGUI()
    {
        Vector3 worldPosition = new Vector3(transform.position.x, transform.position.y + npcHeight, transform.position.z);
        Vector2 position = camera.WorldToScreenPoint(worldPosition);
        position = new Vector2(position.x, Screen.height - position.y);
        Vector2 nameSize = GUI.skin.label.CalcSize(new GUIContent(this.name));
        GUI.color = Color.red;
        GUI.skin.label.fontSize = 16;
        GUI.Label(new Rect(position.x - (nameSize.x / 2), position.y - nameSize.y, nameSize.x, nameSize.y), name);
    }  
}
