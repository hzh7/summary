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
        (x, y)是节点坐标；(_X, _y)是内切圆圆心坐标
        '''
        self._id = None
        self.x = x
        self.y = y
        self.work_direction = rd.random() * 2.0 * math.pi
        self.type = 0#:type: 0 动态节点，else 静态节点
        if Node.angle < math.pi*4/3.0:
            self._r = Node.radius*math.sin(Node.angle/2.0)/(math.sin(Node.angle/2.0) + 1)
            self._x = x + math.cos(self.work_direction)*(Node.radius-self._r)
            self._y = y + math.sin(self.work_direction)*(Node.radius-self._r)
        else:
            self._r = Node.radius * math.cos(math.pi - Node.angle/2.0)
            self._x = x
            self._y = y

    def moveNode(self, point):
        '''
        移动节点
        :param point:list[0, 1]，目标位置的坐标
        '''
        self.x = self.x - self._x + point[0]
        self.y = self.y - self._y + point[1]
        self._x = point[0]
        self._y = point[1]

    def plot(self):
        '''
        plot the Complete Node
        :return:
        '''
        self.polt_Nodepoint()
        self.plot_appro_area()
        self.plot_origin_area()
        self.plot_point()

    def plot_type(self, num):
        '''
        plot the Node when type is num
        :return:
        '''
        if self.type == num:
            self.plot_appro_area()
            #self.plot_origin_area()
            self.plot_point()

    def polt_Nodepoint(self):
        '''
        plot the Nodepoint
        '''
        plt.plot(self.x, self.y, '.b')

    def plot_point(self):
        '''
        plot the 内切圆的圆心
        '''
        plt.plot(self._x, self._y, '.r')

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
        plt.plot(xs, ys, 'b')
        plt.fill(xs, ys, 'b', alpha=0.05)

    def plot_appro_area(self):
        '''
        plot the approximate area
        '''

        ts = np.linspace(0, math.pi*2)
        ps = [self._x+self._y*1j+cmath.exp(1j*t)*self._r for t in ts]
        xs = [i.real for i in ps]
        ys = [i.imag for i in ps]
        '''
        plt.plot(xs, ys, 'g')
        plt.fill(xs, ys, 'g', alpha=0.05)
        '''
        if self.type == -1:
            plt.plot(xs, ys, 'g')
            plt.fill(xs, ys, 'g', alpha=0.05)
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
