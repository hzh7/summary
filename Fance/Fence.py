#coding=utf-8
from Node import Node
from Grid import Grid
from Create import Create
import math
import matplotlib.pyplot as plt

class Fence(object):
    def __init__(self, create_nodes):
        self.nodes = create_nodes

    def Count_nums(self):
        '''
        统计各个区间段内的节点个数
        :return:节点数最多的区间
        '''
        width = self.nodes.width
        section_nums = int(width/(2*Node.radius))
        section = [0]*section_nums
        for i in range(self.nodes.nums):
            if self.nodes.nodes[i].type != -1:
                if int(self.nodes.nodes[i]._y / (2*Node.radius)) < 0:
                    section[0] += 1
                elif int(self.nodes.nodes[i]._y / (2 * Node.radius)) >= section_nums:
                    section[section_nums-1] += 1
                else:
                    section[int(self.nodes.nodes[i]._y / (2*Node.radius))] += 1
        result = 0
        for i in range(section_nums):
            if section[i] > section[result]:
                result = i
        return result

    def N_Distance(self, Node1, Node2):
        return math.sqrt((Node1._x - Node2._x)**2 + (Node1._y - Node2._y)**2)

    def P_Distance(self, Node1, Node_point):
        return math.sqrt((Node1._x - Node_point[0]) ** 2 + (Node1._y - Node_point[1]) ** 2)

    def Creat_Fence(self, k):
        all_engry, all_count = 0, 0
        for ki in range(k):
            MaxCount = self.Count_nums()
            max_y = (MaxCount + 1)*2*Node.radius
            min_y = MaxCount*2*Node.radius
            engry = 0
            #选择区间内最左边的点
            min_x_index = None
            for i in range(self.nodes.nums):
                if min_y <= self.nodes.nodes[i]._y < max_y:
                    if min_x_index == None:
                        min_x_index = i
                    elif self.nodes.nodes[i]._x < self.nodes.nodes[min_x_index]._x:
                        min_x_index = i
            #标记该点
            self.nodes.nodes[min_x_index].type = -1
            #判断最左节点横坐标
            if self.nodes.nodes[min_x_index]._x > self.nodes.nodes[min_x_index]._r:
                self.nodes.nodes[min_x_index].moveNode([self.nodes.nodes[min_x_index]._r, self.nodes.nodes[min_x_index]._y])
                engry = engry + self.Engry(
                    self.nodes.nodes[min_x_index]._x - self.nodes.nodes[min_x_index]._r)

            #print "第 0 个节点"
            #self.nodes.nodes[min_x_index].plot()
            count = 0
            while self.nodes.nodes[min_x_index]._x + self.nodes.nodes[min_x_index]._r < self.nodes.lenth:
                max_x_index = min_x_index
                move_dis = 0
                for i in range(self.nodes.nums):
                    if self.N_Distance(self.nodes.nodes[i], self.nodes.nodes[min_x_index]) <= 2 * self.nodes.nodes[
                        min_x_index]._r:
                        if self.nodes.nodes[i]._x > self.nodes.nodes[max_x_index]._x:
                            max_x_index = i

                #需要移动节点
                if max_x_index == min_x_index:
                    min_distance = None
                    for i in range(self.nodes.nums):
                        if self.nodes.nodes[i].type != -1:
                            # dis 点到目标节点的距离
                            dis = self.P_Distance(self.nodes.nodes[i], [
                                self.nodes.nodes[min_x_index]._x + 2 * self.nodes.nodes[min_x_index]._r,
                                self.nodes.nodes[min_x_index]._y])
                            if min_distance == None:
                                min_distance = dis
                            elif dis < min_distance:
                                min_distance = dis
                                max_x_index = i
                    #移动该节点
                    self.nodes.nodes[max_x_index].moveNode([self.nodes.nodes[min_x_index]._x + 2 * self.nodes.nodes[
                        min_x_index]._r, self.nodes.nodes[min_x_index]._y])
                    engry = engry + self.Engry(min_distance)
                self.nodes.nodes[max_x_index].type = -1   # 标记该点
                min_x_index = max_x_index
                count += 1
                #self.nodes.nodes[min_x_index].plot()
                #print "第",count,"个节点"
            all_count += count
            all_engry += engry
            print "形成第",ki+1,"需要", count, "个节点, 消耗",engry,"j能量"
        print "共形成", k, "条栅栏，需要", all_count, "个节点, 消耗", all_engry, "j能量"
    def Engry(self, dis):
        return dis * 3.6