// 以邻接矩阵为存储结构
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 100

// 计算有向图G出度为0的顶点个数（邻接矩阵）
int calculateOutDegreeZeroInAdjMatrix(int Matrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM], int n)
{
    int outDegreeZeroCount = 0;

    // 遍历每个顶点，检查其出度是否为0
    for (int i = 0; i < n; i++) {
        int outDegree = 0;
        for (int j = 0; j < n; j++) {
            if (Matrix[i][j] != 0) {
                outDegree++;
            }
        }
        if (outDegree == 0) {
            outDegreeZeroCount++;
        }
    }

    return outDegreeZeroCount;
}

// 打印邻接矩阵
void printGraphAdjMatrix(int Matrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM], int n)
{
    printf("Graph (Adjacency Matrix):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // 示例有向图的邻接矩阵表示
    int Matrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM] = {
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };

    // 打印邻接矩阵图
    printGraphAdjMatrix(Matrix, 5);

    // 计算邻接矩阵图的出度为0的顶点个数
    int outDegreeZeroCount_Matrix = calculateOutDegreeZeroInAdjMatrix(Matrix, 5);
    printf("\nNumber of vertices with out-degree zero (Adjacency Matrix): %d\n", outDegreeZeroCount_Matrix);

    return 0;
}
