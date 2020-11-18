# coding=utf-8
from Node import Node
from Grid import Grid
from Create import Create
import math
import matplotlib.pyplot as plt
import random
if __name__ == '__main__':

    nodes = Create(300, 400, math.pi, 10, 300) #产生随机部署点
    plt.figure(1)
    nodes.Plot_Node()
    nodes.Creat_Fence(1)#形成栅栏数

    plt.figure(2)
    nodes.Plot_Node()
    nodes.Plot_type_Node(-1)

    plt.figure(3)
    nodes.Plot_Fence()

    plt.show()
    '''
    eng = 0
    for i in range(51):
        print "第", i, "次实验："
        nodes = Create(300, 400, math.pi, 10, 300)
        eng += nodes.Creat_Fence(1)
        print

    print "50次实验平均消耗能耗", eng / 50.0
    '''