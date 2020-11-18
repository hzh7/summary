from Node import Node
from Grid import Grid
import random
import math
import matplotlib.pyplot as plt
class Create(object):
    def __init__(self, width, lenth, angle, radius, nums):
        self.width = width
        self.lenth = lenth
        Node.angle = angle
        Node.radius = radius
        self.nums = nums
        cx = [random.random() * self.lenth for i in range(nums)]
        cy = [random.random() * self.width for i in range(nums)]
        self.nodes = [Node(cx[i], cy[i]) for i in range(nums)]

    def Plot_Node(self):
        Grid().plot_grid(self.width, self.lenth)
        for i in range(self.nums):
            self.nodes[i].plot()

    def Plot_type_Node(self, num):
        Grid().plot_grid(self.width, self.lenth)
        for i in range(self.nums):
            self.nodes[i].plot_type(-1)

    def Plot_j_Node(self):
        Grid().plot_grid(self.width, self.lenth)
        for i in range(self.nums):
            if self.nodes[i].type != 0:
                self.nodes[i].plot()

    def Plot_d_Node(self):
        Grid().plot_grid(self.width, self.lenth)
        for i in range(self.nums):
            if self.nodes[i].type == 0:
                self.nodes[i].plot()
'''
if __name__ == '__main__':
    a = Create(300, 400, math.pi*9/6.0, 10, 400)
    plt.figure(1)
    a.Plot_Node()

    plt.figure(2)
    a.Plot_j_Node()

    plt.figure(3)
    a.Plot_d_Node()

    plt.show()
    plt.close(1)
    plt.close(2)
    plt.close(3)
'''