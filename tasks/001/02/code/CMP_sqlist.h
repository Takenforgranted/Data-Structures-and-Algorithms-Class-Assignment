#include <stdio.h>
#include <stdlib.h>
#include "sequenlist.h"

int CMP_sqlist(sequenlist* A, sequenlist* B);

sequenlist* InitList();

void ArrayToSequenList(datatype array[], int size, sequenlist* L);

void DestroyList(sequenlist* L);


/*
 * 函数名称: CMP_sqlist
 * 
 * 比较两个顺序表 (sequenlist) A 和 B。
 * 该函数返回:
 *   -1：如果 A 在字典序上小于 B，
 *    0：如果 A 和 B 在字典序上相等，
 *    1：如果 A 在字典序上大于 B。
 *
 * 参数:
 *   A: 指向第一个顺序表的指针
 *   B: 指向第二个顺序表的指针
 *
 * 返回值:
 *   int: 比较结果 (-1, 0, 或 1)
 */
int CMP_sqlist(sequenlist* A, sequenlist* B)
{
    // 比较两个顺序表的长度
    if (A->last > B->last) {
        // A 比 B 长
        return 1;
    }

    // 遍历两个顺序表的元素
    for (int i = 1; i <= A->last; i++) {
        // 比较 A 和 B 的对应元素
        if (A->data[i - 1] < B->data[i - 1]) {
            // A 在字典序上小于 B
            return -1;
        }
        else if (A->data[i - 1] > B->data[i - 1]) {
            // A 在字典序上大于 B
            return 1;
        }
        // 元素相等，继续下一次迭代
    }

    // 两个顺序表在较短的那个长度上相等
    // 检查 A 和 B 是否具有相同的长度
    if (A->last == B->last) {
        // A 和 B 在字典序上相等
        return 0;
    }
}


/**
 * 初始化顺序表
 *
 * 该函数用于创建并初始化一个空的顺序表。
 *
 * @return 返回一个指向新创建的顺序表的指针。
 *         如果内存分配失败，返回NULL。
 */
sequenlist* InitList()
{
    sequenlist* L = (sequenlist*)malloc(sizeof(sequenlist));
    // 检查内存分配是否成功
    if (L == NULL) {
        return NULL;  // 内存分配失败，返回NULL
    }
    L->last = 0;  // 初始化顺序表长度为0，表示空表
    return L;
}


/**
 * 销毁顺序表
 *
 * 该函数用于释放顺序表所占用的内存空间，并将顺序表指针置为NULL。
 *
 * @param L 顺序表指针，指向要销毁的顺序表
 */
void DestroyList(sequenlist* L)
{
    free(L);  // 释放顺序表的内存空间
    L = NULL; // 将顺序表指针置为NULL，防止野指针
}


/**
 * 将数组转换为顺序表
 *
 * 该函数将一个数组的元素逐个复制到顺序表中，并更新顺序表的长度。
 *
 * @param array 要复制的数组
 * @param size 数组的大小
 * @param L 指向目标顺序表的指针
 * @return 无返回值
 */
void ArrayToSequenList(datatype array[], int size, sequenlist* L)
{
    if (L == NULL || size > maxsize) {
        printf("Error - Your wild ambition is too mega!!!\n");
    }
    // 将数组中的元素逐个复制到顺序表中
    for (int i = 0; i < size; i++) {
        L->data[i] = array[i];
    }
    L->last = size; // 更新顺序表的长度
}