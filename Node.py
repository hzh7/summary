# coding=utf-8
import matplotlib.pyplot as plt
import random as rd
import numpy as np
import math
import cmath

class Node(object):
    angle = None
    radius = None
    #work_radius = radius*math.cos(math.pi - Node.angle/2.0)
    def __init__(self, x, y):
        '''
        @param x: the x axis value of Node
        @param y: the y axis value of Node
        '''
        self._id = None
        self._x = x
        self._y = y
        self.work_direction = rd.random() * 2.0 * math.pi
        self.type = rd.randint(0, 2)#:type: 0 动态节点，else 静态节点

    def plot(self):
        '''
        plot the Complete Node
        :return:
        '''
        self.plot_appro_area()
        #self.plot_origin_area()
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

    def plot_point(self):
        '''
        plot the Nodepoint
        '''
        plt.plot(self._x, self._y, '.r')

    def plot_origin_area(self):
        '''
        plot the Node's origin monitoring area
        '''
        a_r = self.work_direction - Node.angle / 2.0
        a_l = self.work_direction + Node.angle / 2.0
        ts = np.linspace(a_r, a_l)
        ps = [self._x+self._y*1j+cmath.exp(1j*t)*Node.radius for t in ts]
        ps2 = [self._x+self._y*1j, self._x+self._y*1j]
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
        ps = [self._x+self._y*1j+cmath.exp(1j*t)*Node.radius*math.cos(math.pi - self.angle/2.0) for t in ts]
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
Node.angle = math.pi*9/6.0
Node.radius = 10
point = Node(50, 46)
point.plot()
point.plot_origin_area()
point.plot_appro_area()
plt.figure(1)
plt.show()
plt.close()
'''
