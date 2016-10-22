# coding=utf-8
from Node import Node
from Grid import Grid
from Create import Create
from Fence import Fence
import math
import matplotlib.pyplot as plt
if __name__ == '__main__':
    for i in range(51):
        print "第", i, "次实验："
        nodes = Create(300, 400, math.pi*8/5.0, 10, 400)
        fence = Fence(nodes)
        fence.Creat_Fence()
        print


    nodes = Create(300, 400, math.pi * 8 / 5.0, 10, 400)
    plt.figure(1)
    nodes.Plot_Node()

    fence = Fence(nodes)
    fence.Creat_Fence()
    Grid().plot_grid(300, 400)
    plt.figure(2)
    nodes.Plot_Node()

    plt.figure(2)
    nodes.Plot_type_Node(-1)
    plt.show()
    plt.close(1)
    plt.close(2)