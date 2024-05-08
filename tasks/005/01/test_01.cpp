#include <stdio.h>
#include <stdlib.h>

// 定义最大顶点数
#define MAX_VERTEX_NUM 100

// 边节点结构体
typedef struct edgenode
{
    int adjvex;              // 邻接点域，存储相邻顶点的下标
    struct edgenode* next;   // 指向下一个邻接点的指针
} edgenode;

// 顶点节点结构体
typedef struct vexnode
{
    edgenode* link;  // 指向第一个邻接点的指针
} vexnode;

// 邻接表转邻接矩阵函数声明
void AdjList2Matrix(vexnode G[], int n, int Matrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]);

int main()
{
    // 示例输入图 G
    vexnode G[3]; // 3个顶点的图
    // 初始化图 G 的邻接表
    G[0].link = (edgenode*)malloc(sizeof(edgenode));
    G[0].link->adjvex = 1;
    G[0].link->next = (edgenode*)malloc(sizeof(edgenode));
    G[0].link->next->adjvex = 2;
    G[0].link->next->next = NULL;

    G[1].link = (edgenode*)malloc(sizeof(edgenode));
    G[1].link->adjvex = 0;
    G[1].link->next = (edgenode*)malloc(sizeof(edgenode));
    G[1].link->next->adjvex = 2;
    G[1].link->next->next = NULL;

    G[2].link = (edgenode*)malloc(sizeof(edgenode));
    G[2].link->adjvex = 0;
    G[2].link->next = (edgenode*)malloc(sizeof(edgenode));
    G[2].link->next->adjvex = 1;
    G[2].link->next->next = NULL;

    // 定义邻接矩阵
    int Matrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    // 调用邻接表转邻接矩阵函数
    AdjList2Matrix(G, 3, Matrix);

    // 打印生成的邻接矩阵
    printf("Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// 邻接表转邻接矩阵实现
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
