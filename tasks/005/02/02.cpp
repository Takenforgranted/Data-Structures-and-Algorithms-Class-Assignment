#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// 初始化有向图
void initGraph(Graph* G, int n)
{
    G->vertexNum = n;
    G->edgeNum = 0;

    // 初始化邻接表
    for (int i = 0; i < n; i++) {
        G->vertices[i].vertex = 'A' + i;
        G->vertices[i].link = NULL;
    }
}

// 添加有向边
void addDirectedEdge(Graph* G, int i, int j)
{
    EdgeNode* newNode = (EdgeNode*)malloc(sizeof(EdgeNode));
    newNode->adjvex = j;
    newNode->next = G->vertices[i].link;
    G->vertices[i].link = newNode;
    G->edgeNum++;
}

// DFS遍历判断路径是否存在
bool DFS(Graph* G, int v, int w, bool* visited)
{
    if (v == w) {
        return true; // 找到路径
    }

    visited[v] = true; // 标记当前顶点为已访问

    EdgeNode* p = G->vertices[v].link;
    while (p) {
        if (!visited[p->adjvex] && DFS(G, p->adjvex, w, visited)) {
            return true;
        }
        p = p->next;
    }

    return false;
}

// BFS遍历判断路径是否存在
bool BFS(Graph* G, int v, int w)
{
    if (v == w) {
        return true; // 起点就是终点
    }

    bool visited[MAX_VERTEX_NUM] = { false };
    int queue[MAX_VERTEX_NUM];
    int front = 0, rear = 0;

    visited[v] = true;
    queue[rear++] = v;

    while (front < rear) {
        int cur = queue[front++];

        EdgeNode* p = G->vertices[cur].link;
        while (p) {
            if (!visited[p->adjvex]) {
                if (p->adjvex == w) {
                    return true; // 找到路径
                }
                visited[p->adjvex] = true;
                queue[rear++] = p->adjvex;
            }
            p = p->next;
        }
    }

    return false;
}

// 打印邻接表
void printGraph(Graph* G)
{
    printf("Graph:\n");
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
    Graph G;
    int n = 5; // 顶点数
    initGraph(&G, n);

    // 直接使用示例图
    int edges[][2] = { {0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4} };
    for (int k = 0; k < 6; k++) {
        addDirectedEdge(&G, edges[k][0], edges[k][1]);
    }

    // 打印图的邻接表
    printGraph(&G);

    // 判断路径是否存在
    int startVertex = 0; // 起点为顶点A
    int endVertex = 4;   // 终点为顶点E

    printf("\nDFS: Path from %c to %c %s\n", G.vertices[startVertex].vertex, G.vertices[endVertex].vertex,
        DFS(&G, startVertex, endVertex, (bool*)calloc(n, sizeof(bool))) ? "exists" : "does not exist");

    printf("BFS: Path from %c to %c %s\n", G.vertices[startVertex].vertex, G.vertices[endVertex].vertex,
        BFS(&G, startVertex, endVertex) ? "exists" : "does not exist");

    return 0;
}
