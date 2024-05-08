import networkx as nx
import matplotlib.pyplot as plt

# 示例有向图的邻接矩阵表示
matrix = [
    [0, 1, 1, 0, 0],
    [0, 0, 0, 1, 0],
    [0, 0, 0, 1, 1],
    [0, 0, 0, 0, 1],
    [0, 0, 0, 0, 0]
]

# 示例有向图的邻接表表示
edges_adjList = [(0, 1), (0, 2), (1, 3), (2, 3), (2, 4), (3, 4)]

# 创建有向图
G = nx.DiGraph()

# 添加节点
for i in range(len(matrix)):
    G.add_node(i)

# 添加边
for edge in edges_adjList:
    G.add_edge(edge[0], edge[1])

# 画图
pos = nx.spring_layout(G)  # 选择布局
nx.draw(G, pos, with_labels=True, font_weight='bold',
        node_size=700, node_color="skyblue", arrowsize=20)

# 显示图形
plt.savefig("sample_input.png", dpi=600)
plt.show()
