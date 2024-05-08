// 以邻接表为存储结构
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 100

// 邻接表中表示边的结构体
typedef struct Node
{
    int adjvex;          // 邻接顶点的下标
    struct Node* next;   // 下一个邻接顶点
} EdgeNode;

// 顶点结构体
typedef struct
{
    char vertex;       // 顶点信息
    EdgeNode* link;    // 邻接表头指针
} VertexNode;

// 邻接表图结构体
typedef struct
{
    VertexNode vertices[MAX_VERTEX_NUM];
    int vertexNum;     // 顶点数
    int edgeNum;       // 边数
} Graph;

// 计算有向图G出度为0的顶点个数（邻接表）
int calculateOutDegreeZeroInAdjList(Graph* G)
{
    int outDegreeZeroCount = 0;

    // 遍历每个顶点，检查其出度是否为0
    for (int i = 0; i < G->vertexNum; i++) {
        EdgeNode* p = G->vertices[i].link;
        if (p == NULL) {
            outDegreeZeroCount++;
        }
    }

    return outDegreeZeroCount;
}

// 打印邻接表
void printGraphAdjList(Graph* G)
{
    printf("Graph (Adjacency List):\n");
    for (int i = 0; i < G->vertexNum; i++) {
        printf("%c -> ", G->vertices[i].vertex);
        EdgeNode* p = G->vertices[i].link;
        while (p) {
            if (p->next != NULL) {
                printf("%c -> ", G->vertices[p->adjvex].vertex);
            }
            else {
                printf("%c", G->vertices[p->adjvex].vertex);
            }
            p = p->next;
        }
        printf("\n");
    }
}

int main()
{
    // 初始化邻接表图
    Graph G_adjList;
    G_adjList.vertexNum = 5; // 顶点数
    G_adjList.edgeNum = 0;

    // 初始化邻接表
    for (int i = 0; i < 5; i++) {
        G_adjList.vertices[i].vertex = 'A' + i;
        G_adjList.vertices[i].link = NULL;
    }

    // 示例有向图的邻接表表示
    int edges_adjList[][2] = { {0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4} };
    for (int k = 0; k < 6; k++) {
        EdgeNode* newNode = (EdgeNode*)malloc(sizeof(EdgeNode));
        newNode->adjvex = edges_adjList[k][1];
        newNode->next = G_adjList.vertices[edges_adjList[k][0]].link;
        G_adjList.vertices[edges_adjList[k][0]].link = newNode;
        G_adjList.edgeNum++;
    }

    // 打印邻接表图
    printGraphAdjList(&G_adjList);

    // 计算邻接表图的出度为0的顶点个数
    int outDegreeZeroCount_adjList = calculateOutDegreeZeroInAdjList(&G_adjList);
    printf("\nNumber of vertices with out-degree zero (Adjacency List): %d\n", outDegreeZeroCount_adjList);

    return 0;
}
