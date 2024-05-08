import networkx as nx
import matplotlib.pyplot as plt

# 定义图的边
edges = [('A', 'B'), ('A', 'C'), ('B', 'C'), ('B', 'D'),
         ('C', 'D'), ('C', 'E'), ('D', 'E')]

# 创建图对象
G = nx.Graph()

# 添加边到图中
G.add_edges_from(edges)

# 绘制图形
pos = nx.spring_layout(G)
nx.draw(G, pos, with_labels=True, node_size=700, node_color='skyblue',
        font_size=10, font_color='black', font_weight='bold', font_family='sans-serif')

# 显示图形
plt.savefig('sample_figure.png', dpi=600)
plt.show()
