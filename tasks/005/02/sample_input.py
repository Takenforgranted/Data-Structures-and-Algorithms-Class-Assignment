import networkx as nx
import matplotlib.pyplot as plt

# 创建有向图
G = nx.DiGraph()

# 添加边
edges = [('A', 'B'), ('A', 'C'), ('B', 'D'),
         ('C', 'D'), ('C', 'E'), ('D', 'E')]
G.add_edges_from(edges)

# 绘制图形
pos = nx.spring_layout(G)  # 选择布局
nx.draw(G, pos, with_labels=True, font_weight='bold', node_size=700,
        node_color='skyblue', font_size=10, arrowsize=20)

# 显示图形
plt.savefig('sample_input.png', dpi=600)
plt.show()
