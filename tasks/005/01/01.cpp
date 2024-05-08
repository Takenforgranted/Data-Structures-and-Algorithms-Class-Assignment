#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 100 // 定义图的最大顶点数

typedef char vextype;
typedef struct node
{
	int adjvex;
	struct node* next;
} edgenode;

typedef struct
{
	vextype vertex;
	edgenode* link;
} vexnode;

void AdjList2Matrix(vexnode G[], int n, int Matrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM])
{
	int i, j;
	// 初始化邻接矩阵
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			Matrix[i][j] = 0;
		}
	}
	// 将邻接表转换为邻接矩阵
	for (i = 0; i < n; i++) {
		edgenode* s = G[i].link;
		while (s != NULL) {
			int temp = s->adjvex;
			Matrix[i][temp] = 1;
			s = s->next;
		}
	}
}

// 打印邻接矩阵
void PrintMatrix(int Matrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM], int n)
{
	// 输出提示信息
	printf("Matrix:\n");

	// 遍历二维数组并输出元素
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 使用printf将矩阵元素输出到控制台
			printf("%d ", Matrix[i][j]);
		}
		// 输出换行符，表示矩阵的一行输出结束
		printf("\n");
	}
}

int main()
{
	// 顶点数和边数
	int n = 5;
	int e = 6;

	// 创建邻接表
	vexnode G[MAX_VERTEX_NUM];
	char vertices[] = { 'A', 'B', 'C', 'D', 'E' };
	int edges[][2] = { {0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4} };

	// 输入顶点信息
	for (int k = 0; k < n; k++) {
		G[k].vertex = vertices[k];
		G[k].link = NULL;
	}

	// 输入边信息
	for (int k = 0; k < e; k++) {
		int i = edges[k][0];
		int j = edges[k][1];
		// 创建新节点，表示边(i, j)
		edgenode* s = (edgenode*)malloc(sizeof(edgenode));
		s->adjvex = j;
		s->next = G[i].link;
		G[i].link = s;
		// 由于是无向图，还需要创建新节点，表示边(j, i)
		s = (edgenode*)malloc(sizeof(edgenode));
		s->adjvex = i;
		s->next = G[j].link;
		G[j].link = s;
	}

	// 创建邻接矩阵
	int Matrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	// 转换邻接表为邻接矩阵
	AdjList2Matrix(G, n, Matrix);
	// 打印邻接矩阵
	PrintMatrix(Matrix, n);

	return 0;
}

