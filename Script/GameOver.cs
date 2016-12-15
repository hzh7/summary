using UnityEngine;
using UnityEngine.UI;

public class GameOver : MonoBehaviour {

    private Button[] buttons;
    private GameObject image;
    void Awake()
    {
         // Get the buttons
         buttons = GetComponentsInChildren<Button>();

         image = transform.Find("Image-M").gameObject;
         HideImage();
         HideButtons();
        //transform.gameObject.SetActive(false);
    }
    void Start()
    {
        
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
        GameObject.Find("Canvas/Panel/Image-M/lenth").GetComponent<Text>().text = "长度   " + GameObject.Find("script").GetComponent<Leaderboard>().getSco();
        GameObject.Find("Canvas/Panel/Image-M/kill").GetComponent<Text>().text = "击杀   " + GameObject.Find("script").GetComponent<Leaderboard>().getkil();
        GameObject.Find("Canvas/Panel/Image-M/dabai").GetComponent<Text>().text = "打败了 " + (GameObject.Find("script").GetComponent<Leaderboard>().getSco() / 608f).ToString("f3")+" %的玩家";
        //transform.gameObject.SetActive(true);
        image.SetActive(true);
    }
    public void ExitToMenu()
    {
        // Reload the level
        Application.LoadLevel("Menu 1");
    }

    //重来
    public void RestartGame()
    {
        // Reload the level
        Application.LoadLevel("newSnake");
    }
}