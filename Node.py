# coding=utf-8
import matplotlib.pyplot as plt
import random as rd
import numpy as np
import math
import cmath

class Node(object):
    angle = None
    radius = None
    def __init__(self, x, y):
        '''
        @param x: the x axis value of Node
        @param y: the y axis value of Node
        (x, y)是节点坐标；
        '''
       # self._id = None
        self.x = x
        self.y = y
        self.ID = -1
        self.work_direction = rd.random() * 2.0 * math.pi
        self.type = 0#:type: 0 动态节点，else 静态节点

    def moveNode(self, point):
        '''
        移动节点
        :param point:list[0, 1]，目标位置的坐标
        '''
        self.x = point[0]
        self.y = point[1]

    def plot(self):
        '''
        plot the Complete Node
        :return:
        '''
        self.plot_Nodepoint()
        self.plot_origin_area()

    def plot_type(self, num):
        '''
        plot the Node when type is num
        :return:
        '''
        if self.type == num:
            self.plot()
            plt.fill(self.x, self.y, '.r', alpha=0.05)

    def plot_Nodepoint(self):
        '''
        plot the Nodepoint
        '''
        plt.plot(self.x, self.y, '.b')


    def plot_origin_area(self):
        '''
        plot the Node's origin monitoring area
        '''
        a_r = self.work_direction - Node.angle / 2.0
        a_l = self.work_direction + Node.angle / 2.0
        ts = np.linspace(a_r, a_l)
        ps = [self.x+self.y*1j+cmath.exp(1j*t)*Node.radius for t in ts]
        ps2 = [self.x+self.y*1j, self.x+self.y*1j]
        ps2[1:1] = ps
        xs = [i.real for i in ps2]
        ys = [i.imag for i in ps2]
        if self.type == -1:
            plt.plot(xs, ys, 'r')
            plt.fill(xs, ys, 'r', alpha=0.05)
        else:
            plt.plot(xs, ys, 'b')
            plt.fill(xs, ys, 'r', alpha=0.1)

'''
Node.angle = math.pi/3.0
Node.radius = 10
point = Node(100, 100)
point.polt_Nodepoint()
point.plot_origin_area()

point.plot_point()
point.plot_appro_area()
plt.figure(1)
plt.show()
plt.close()
'''
