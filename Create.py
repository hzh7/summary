#coding=utf-8
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
        self.tag = 0
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

    def Count_nums(self):
        '''
        统计各个区间段内的节点个数
        :return:节点数最多的区间
        '''
        width = self.width
        section_nums = int(width / (2 * Node.radius))
        section = [0] * section_nums
        for i in range(self.nums):
            if self.nodes[i].type != -1:
                if int(self.nodes[i].y / (2 * Node.radius)) < 0:
                    section[0] += 1
                elif int(self.nodes[i].y / (2 * Node.radius)) >= section_nums:
                    section[section_nums - 1] += 1
                else:
                    section[int(self.nodes[i].y / (2 * Node.radius))] += 1
        result = 0
        print section
        for i in range(section_nums):
            if section[i] > section[result]:
                result = i
        return result

    def N_Distance(self, Node1, Node2):
        return math.sqrt((Node1.x - Node2.x) ** 2 + (Node1.y - Node2.y) ** 2)

    def P_Distance(self, Node1, Node_point):
        return math.sqrt((Node1.x - Node_point[0]) ** 2 + (Node1.y - Node_point[1]) ** 2)

    def Creat_Fence(self, k):
        all_engry, all_count = 0, 0
        for ki in range(k):
            count = 0
            FenceA = []
            MaxCount = self.Count_nums()
            max_y = (MaxCount + 1) * 2 * Node.radius
            min_y = MaxCount * 2 * Node.radius
            engry = 0
            # 选择区间内最左边的点
            min_x_index = None
            for i in range(self.nums):
                if min_y <= self.nodes[i].y < max_y and self.nodes[i].type != -1:
                    if min_x_index == None:
                        min_x_index = i
                    elif self.nodes[i].x < self.nodes[min_x_index].x:
                        min_x_index = i
            # 标记该点并编号
            self.nodes[min_x_index].type = -1
            # self.nodes[min_x_index].ID = count
            FenceA.append(min_x_index)

            # 判断最左节点横坐标
            if self.nodes[min_x_index].x > self.nodes[min_x_index].radius:
                self.nodes[min_x_index].moveNode(
                    [self.nodes[min_x_index].radius, self.nodes[min_x_index].y])
                engry = engry + self.MoveEngry(
                    self.nodes[min_x_index].x - self.nodes[min_x_index].radius)

            # print "第 0 个节点"
            # self.nodes[min_x_index].plot()
            max_x_index = min_x_index
            try:
                while self.nodes[min_x_index].x + Node.radius < self.lenth:
                    move_dis = 0
                    for i in range(self.nums):
                        if self.N_Distance(self.nodes[i], self.nodes[min_x_index]) <= 2 * Node.radius:
                            if self.nodes[i].x > self.nodes[max_x_index].x:
                                max_x_index = i

                    # 需要移动节点
                    if max_x_index == min_x_index:
                        min_distance = 0
                        for i in range(self.nums):
                            # dis 点到目标节点的距离
                            dis = self.P_Distance(self.nodes[i], [
                                self.nodes[min_x_index].x + 2 * self.nodes[min_x_index].radius,
                                self.nodes[min_x_index].y])
                            if self.nodes[i].type != -1:# and dis <= 2*Node.radius:
                                if dis < min_distance or min_distance == 0:
                                    min_distance = dis
                                    max_x_index = i
                                    #self.nodes[max_x_index].ID = self.ID

                        if max_x_index == min_x_index:
                            raise Exception("无法形成栅栏")
                        # 移动该节点
                        self.nodes[max_x_index].moveNode([self.nodes[min_x_index].x + 2 * self.nodes[
                            min_x_index].radius, self.nodes[min_x_index].y])
                        engry = engry + self.MoveEngry(min_distance)

                    #标记该点并编号
                    self.nodes[max_x_index].type = -1
                    count += 1
                    # self.nodes[max_x_index].ID = count
                    FenceA.append(max_x_index)
                    min_x_index = max_x_index
                    # self.nodes[min_x_index].plot()
                    # print "第",count,"个节点"
            except Exception, ex:
                print Exception, ":", ex
                exit(0)

            engry += self.Rotation_Angle(count, FenceA)
            all_count += count
            all_engry += engry
            print "形成第", ki + 1, "需要", count + 1, "个节点, 消耗", engry, "j能量"
        if k != 1:
            print "共形成", k, "条栅栏，需要", all_count + k, "个节点, 消耗", all_engry, "j能量"
        return all_engry

    def Rotation_Angle(self, count, FenceA):
        engry = 0
        id, front, mid, back = 0, 0, 0, 0
        while id<count-1:
            front = FenceA[id]
            mid = FenceA[id + 1]
            back = FenceA[id + 2]
            dir = math.atan((self.nodes[back].y - self.nodes[front].y)/(self.nodes[back].x - self.nodes[front].x))
            k1 = (self.nodes[back].y - self.nodes[front].y) / (self.nodes[back].x - self.nodes[front].x)
            k2 = (self.nodes[mid].y - self.nodes[front].y) / (self.nodes[mid].x - self.nodes[front].x)
            if k1>= k2:
                engry += self.RotaEngry(dir + math.pi / 2 - self.nodes[mid].work_direction)
                self.nodes[mid].work_direction = dir + math.pi / 2
            else:
                engry += self.RotaEngry(dir + math.pi / 2 - self.nodes[mid].work_direction)
                self.nodes[mid].work_direction = dir - math.pi / 2
            id += 1
        # 第一个
        dir = math.atan((self.nodes[FenceA[1]].y - self.nodes[FenceA[0]].y) / (self.nodes[FenceA[1]].x))
        if self.nodes[FenceA[1]].y > self.nodes[FenceA[0]].y:
            engry += self.RotaEngry(dir + math.pi / 2 - self.nodes[mid].work_direction)
            self.nodes[FenceA[0]].work_direction = dir + math.pi / 2
        else:
            engry += self.RotaEngry(dir + math.pi / 2 - self.nodes[mid].work_direction)
            self.nodes[FenceA[0]].work_direction = dir - math.pi / 2
        # 最后一个
        dir = math.atan((self.nodes[FenceA[count]].y - self.nodes[FenceA[count - 1]].y) / (self.width - self.nodes[FenceA[count - 1]].x))
        if self.nodes[FenceA[count]].y < self.nodes[FenceA[count - 1]].y:
            engry += self.RotaEngry(dir + math.pi / 2 - self.nodes[mid].work_direction)
            self.nodes[FenceA[count]].work_direction = dir + math.pi / 2
        else:
            engry += self.RotaEngry(dir + math.pi / 2 - self.nodes[mid].work_direction)
            self.nodes[FenceA[count]].work_direction = dir - math.pi / 2
        return engry

    def MoveEngry(self, dis):
        return float(dis) * 3.6

    def RotaEngry(self, angle):
        return float(angle) * 1.8 / math.pi

    def Plot_Fence(self):
        Grid().plot_grid(self.width, self.lenth)
        for i in range(self.nums):
            if self.nodes[i].type == -1:
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