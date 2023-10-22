#include <stdio.h>
#include <stdlib.h>
#include "s_link.h"

void DeleteList(s_linklist* L, datatype min, datatype max);

s_node* InitSingleNode();

s_linklist* InitSingleLinkedList();

void ArrayToSingleLinkList(datatype a[], int size, s_linklist* L);


/**
 * @brief 从单链表中删除数据范围内的元素
 *
 * 该函数用于从给定单链表中删除数据值在[min, max]范围内的元素。
 *
 * @param L 指向目标单链表的指针
 * @param min 最小数据值
 * @param max 最大数据值
 *
 * @return 无返回值
 */
void DeleteList(s_linklist* L, datatype min, datatype max)
{
    s_node* current = L->head;  // 从链表头结点开始

    // 遍历链表，查找比min大或者比max小的元素的前一个元素位置
    while (current->next != NULL) {
        while (current->next->data > min && current->next->data < max) {
            s_node* out = current->next;
            current->next = out->next;
            free(out);  // 释放需要删除的结点内存
        }
        current = current->next;
    }
}



/**
 * @brief 初始化单链表结点
 *
 * 该函数用于创建并初始化一个单链表结点，包括数据域和指向下一个结点的指针。
 *
 * @return 返回指向新创建的结点的指针，如果内存分配失败，则返回NULL。
 */
s_node* InitSingleNode()
{
    s_node* node = (s_node*)malloc(sizeof(s_node));

    // 检查内存分配是否成功
    if (node == NULL) {
        return NULL;  // 内存分配失败，返回NULL
    }

    node->data = 0;       // 初始化数据域
    node->next = NULL;    // 初始化下一个结点指针为NULL
    return node;
}


/**
 * @brief 初始化单链表
 *
 * 该函数用于创建并初始化一个单链表，包括链表头指针。
 *
 * @return 返回指向新创建的单链表的指针，如果内存分配失败，则返回NULL。
 */
s_linklist* InitSingleLinkedList()
{
    s_linklist* L = (s_linklist*)malloc(sizeof(s_linklist));

    // 检查内存分配是否成功
    if (L == NULL) {
        return NULL;  // 内存分配失败，返回NULL
    }
    L->head = InitSingleNode(); // 初始化头结点
    L->head->next = NULL;  // 初始化头结点指向NULL

    return L;
}


/**
 * @brief 打印单向链表内容
 *
 * 该函数用于打印单向链表中的数据元素，以及链表的状态。
 *
 * @param L 指向要打印的单向链表的指针
 *
 * @return 无返回值
 */
void PrintLinkList(const s_linklist* L)
{
    printf("LinkList is: ");
    if (L->head->next == NULL) {
        printf("Empty!!!\n");
    }
    else {
        s_node* current = L->head->next;  // 从链表头节点开始
        while (current != NULL) {
            printf("%.1f ", current->data);  // 打印当前结点的数据
            current = current->next;  // 移动到下一个结点
        }
        printf("\n");
    }
}


/**
 * @brief 将数组转换为单向链表
 *
 * 该函数用于将给定数组的数据元素转换为单向链表的结点，连接它们并构建一个单向链表。
 *
 * @param a 数组，包含要转换为链表的数据元素
 * @param size 数组的大小，即要转换的数据元素数量
 * @param L 指向目标单向链表的指针
 *
 * @return 无返回值
 */
void ArrayToSingleLinkList(datatype a[], int size, s_linklist* L)
{
    if (L == NULL || size == 0) {
        printf("Error - Invalid pointer to the destination list.\n");
        return;
    }
    s_node* current = L->head;  // 从链表头节点开始
    // 遍历数组并转换为链表结点
    for (int i = 0; i < size; i++) {
        s_node* new_node = InitSingleNode();  // 初始化新结点
        if (new_node == NULL) {
            printf("Error - Memory allocation failed.\n");
            return;
        }
        new_node->data = a[i];  // 设置结点的数据
        new_node->next = NULL;  // 初始化下一个结点指针为NULL
        // 如果链表为空，将新结点设置为链表的头
        if (L->head == NULL) {
            L->head->next = new_node;
            current = new_node;
        }
        else {
            current->next = new_node;  // 连接新结点到当前结点的下一个
            current = new_node;  // 更新当前结点为新结点
        }
    }
}

