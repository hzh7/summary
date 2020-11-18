import matplotlib.pyplot as plt

class Grid(object):
    def plot_grid(self, width, lenth):
        a = [i for i in range(width)]
        b = [i for i in range(lenth)]
        c1 = [0 for i in range(width)]
        c2 = [0 for i in range(lenth)]
        d1 = [width for i in range(lenth)]
        d2 = [lenth for i in range(width)]
        plt.plot(c1, a, 'r--')
        plt.plot(b, c2, 'r--')
        plt.plot(b, d1, 'r--')
        plt.plot(d2, a, 'r--')
        for row in range(width/10-1):
            t = [row*10+10 for i in range(lenth)]
            plt.plot(b, t, 'b-.')
        for col in range(lenth/10-1):
            t = [col*10+10 for i in range(width)]
            plt.plot(t, a, 'b-.')

'''
a = Grid().plot_grid(300, 400)
plt.figure(1)
plt.show()
plt.close()
'''