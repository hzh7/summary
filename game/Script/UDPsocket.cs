﻿/*
*该脚本用于实现用户数据的同步，每当游戏结束，会自动向服务器发现本场游戏中的玩家表现
*/
using UnityEngine;
using System.Collections;
using System.Net;
using System.Net.Sockets;
using System.Text;

public class UDPsocket : MonoBehaviour {
    public static UDPsocket Instance;
    private static IPAddress GroupAddress = IPAddress.Parse("182.254.227.81");
    private static int GroupPort = 28888;

    private void Send(string message)
    {
        UdpClient sender = new UdpClient();
        IPEndPoint groupEP = new IPEndPoint(GroupAddress, GroupPort);

        
        byte[] bytes = Encoding.ASCII.GetBytes(message);
        sender.Send(bytes, bytes.Length, groupEP);
        sender.Close();
        

    }
    public void Main()
    {
       // Debug.Log("Main");
        int sco = Snake.InstanceSnake.getScore();
        string score = string.Format("{0} + {1}", "i:", sco);
        Send(score);
    }
}
