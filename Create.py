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
        x = [random.random() * self.lenth for i in range(self.lenth)]
        y = [random.random() * self.width for i in range(self.width)]
        self.nodes = [Node(x[i], y[i]) for i in range(nums)]

    def Plot_Node(self):
        Grid().plot_grid(self.width, self.lenth)
        for i in range(self.nums):
            #self.nodes[i].plot()
            self.nodes[i].plot_appro_area()
if __name__ == '__main__':
    a = Create(300, 400, math.pi*9/6.0, 10, 300)
    a.Plot_Node()
    plt.figure(1)
    plt.show()
    plt.close()
