/*
*该脚本主要实现游戏结束后显示的界面，包括三个按键进入不同功能
*/
using UnityEngine;
using UnityEngine.UI;

public class GameOver : MonoBehaviour {
    private Button[] buttons;
    private GameObject image;
    void Awake()
    {
         buttons = GetComponentsInChildren<Button>();
         image = transform.Find("Image-M").gameObject;
         HideImage();
         HideButtons();
    }

    public void HideButtons()
    {
        foreach (var b in buttons)
        {
            b.gameObject.SetActive(false);
        }
    }

    public void HideImage()
    {
        image.SetActive(false);
    }

    public void ShowButtons()
    {
        foreach (var b in buttons)
        {
            b.gameObject.SetActive(true);
        }
    }

    public void ShowImage()
    {
        float a = GameObject.Find("script").GetComponent<Leaderboard>().getSco();
        GameObject.Find("Canvas/Panel/Image-M/lenth").GetComponent<Text>().text = "长度   " +
            GameObject.Find("script").GetComponent<Leaderboard>().getSco();
        GameObject.Find("Canvas/Panel/Image-M/kill").GetComponent<Text>().text = "击杀   " + 
            GameObject.Find("script").GetComponent<Leaderboard>().getkil();
        GameObject.Find("Canvas/Panel/Image-M/dabai").GetComponent<Text>().text = "打败了 " + 
            (a / (a+500f)).ToString("f3")+" %的玩家";
        image.SetActive(true);
    }

    public void ExitToMenu()
    {
        Application.LoadLevel("Menu 1");
    }
    
    public void RestartGame()
    {
        Application.LoadLevel("newSnake");
    }
}