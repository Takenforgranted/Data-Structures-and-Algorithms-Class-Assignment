#include <stdio.h>
#include <stdlib.h>

#define INF 10000
#define NUM_VERTICES 8

// 结构体定义：用于存储图的邻接矩阵
typedef struct
{
    int matrix[NUM_VERTICES][NUM_VERTICES];
} GraphMatrix;

// 结构体定义：用于存储路径信息
typedef struct
{
    int** next;
} PathInfo;

// 打印矩阵
void printMatrix(int matrix[NUM_VERTICES][NUM_VERTICES], const char* name)
{
    printf("%s matrix:\n", name);
    for (int i = 0; i < NUM_VERTICES; ++i) {
        for (int j = 0; j < NUM_VERTICES; ++j) {
            if (matrix[i][j] == INF) {
                printf("INF ");
            }
            else {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Floyd-Warshall算法
void floydWarshall(GraphMatrix* graph, PathInfo* pathInfo)
{
    int n = NUM_VERTICES;

    // 初始化路径信息
    pathInfo->next = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        pathInfo->next[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; ++j) {
            pathInfo->next[i][j] = j;
        }
    }

    // 初始状态
    printf("----------- Initialization -----------\n");
    printMatrix(graph->matrix, "Initial Distance");
    printMatrix((int(*)[NUM_VERTICES])pathInfo->next, "Initial Path");

    // Floyd-Warshall算法
    for (int k = 0; k < n; ++k) {
        printf("----------- Step %d -----------\n", k + 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph->matrix[i][k] + graph->matrix[k][j] < graph->matrix[i][j]) {
                    graph->matrix[i][j] = graph->matrix[i][k] + graph->matrix[k][j];
                    pathInfo->next[i][j] = pathInfo->next[i][k];

                    // 每次更新后打印状态
                    printMatrix(graph->matrix, "Updated Distance");
                    printMatrix((int(*)[NUM_VERTICES])pathInfo->next, "Updated Path");
                }
            }
        }
    }
}

// 打印从起点到终点的最短路径
void printShortestPath(int start, int end, PathInfo* pathInfo)
{
    printf("Shortest path from %d to %d: ", start, end);

    if (pathInfo->next[start][end] == end) {
        printf("%d -> %d\n", start, end);
    }
    else {
        printf("%d", start);
        while (start != end) {
            start = pathInfo->next[start][end];
            printf(" -> %d", start);
        }
        printf("\n");
    }
}

int main()
{
    // 初始化邻接矩阵，使用INF表示无穷大
    GraphMatrix graph;
    for (int i = 0; i < NUM_VERTICES; ++i) {
        for (int j = 0; j < NUM_VERTICES; ++j) {
            graph.matrix[i][j] = INF;
        }
    }

    // 给定图的关系
    graph.matrix[0][1] = 16;  // A->B
    graph.matrix[0][6] = 11;  // A->G
    graph.matrix[0][3] = 2;   // A->D
    graph.matrix[1][2] = 6;   // B->C
    graph.matrix[3][2] = 8;   // D->C
    graph.matrix[3][4] = 3;   // D->E
    graph.matrix[5][6] = 7;   // F->G
    graph.matrix[5][4] = 2;   // F->E
    graph.matrix[7][5] = 4;   // H->F
    graph.matrix[7][1] = 5;   // H->B

    // 对角线元素设为0
    for (int i = 0; i < NUM_VERTICES; ++i) {
        graph.matrix[i][i] = 0;
    }

    // 打印初始距离矩阵
    printf("Initial Distance Matrix:\n");
    for (int i = 0; i < NUM_VERTICES; ++i) {
        for (int j = 0; j < NUM_VERTICES; ++j) {
            if (graph.matrix[i][j] == INF) {
                printf("INF ");
            }
            else {
                printf("%d ", graph.matrix[i][j]);
            }
        }
        printf("\n");
    }

    // 运行Floyd-Warshall算法
    PathInfo pathInfo;
    floydWarshall(&graph, &pathInfo);

    // 打印运行Floyd-Warshall后的最终距离矩阵
    printf("\nFinal Distance Matrix after Floyd-Warshall:\n");
    printMatrix(graph.matrix, "Final Distance");

    // 打印运行Floyd-Warshall后的最终路径矩阵
    printf("\nFinal Path Matrix after Floyd-Warshall:\n");
    printMatrix((int(*)[NUM_VERTICES])pathInfo.next, "Final Path");

    // 找到并打印从A到其他节点的最短路径
    for (int i = 1; i < NUM_VERTICES; ++i) {
        printShortestPath(0, i, &pathInfo);
        if (graph.matrix[0][i] == INF) {
            printf("Shortest Distance: Infinity\n");
        }
        else {
            printf("Shortest Distance: %d\n", graph.matrix[0][i]);
        }
    }

    // 释放内存
    for (int i = 0; i < NUM_VERTICES; ++i) {
        free(pathInfo.next[i]);
    }
    free(pathInfo.next);

    return 0;
}
