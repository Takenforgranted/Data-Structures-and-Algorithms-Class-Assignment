#include <stdio.h>
#include <stdlib.h>
#include "s_link.h"

s_linklist* MergeLink(s_linklist* a, s_linklist* b);

s_node* InitSingleNode();

s_linklist* InitSingleLinkedList();

void ArrayToSingleLinkList(datatype a[], int size, s_linklist* L);

/*
这部分没搞懂，算法流程很难想，毕竟是三个单链表之间倒来倒去非常抽象，求指导。
*/
/**
 * @brief 合并两个有序单链表为一个递增有序的单链表
 *
 * 该函数将两个有序单链表a和b合并为一个递增有序的单链表c。
 * 合并后的单链表c是新创建的链表，不会修改原始链表a和b。
 *
 * @param a 指向第一个有序单链表的指针
 * @param b 指向第二个有序单链表的指针
 *
 * @return 指向新合并的递增有序单链表c的指针
 */
s_linklist* MergeLink(s_linklist* a, s_linklist* b)
{
    // 创建一个新链表 c 用于存储合并后的结果
    s_linklist* c = InitSingleLinkedList();
    s_node* p = a->head->next; // 指向链表 a 的第一个结点
    s_node* q = b->head->next; // 指向链表 b 的第一个结点
    s_node* current = c->head; // 指向链表 c 的当前结点

    // 遍历链表 a 和链表 b，比较结点的值，并将较小值的结点加入链表 c
    while (p != NULL && q != NULL) {
        if (p->data >= q->data) {
            current->next = p; // 将 p 结点加入 c
            p = p->next; // 移动到 a 的下一个结点
        } else {
            current->next = q; // 将 q 结点加入 c
            q = q->next; // 移动到 b 的下一个结点
        }
        current = current->next; // 移动到 c 的下一个结点
    }

    // 如果 a 或 b 还有剩余结点，直接加入 c
    if (p != NULL) {
        current->next = p;
    }
    if (q != NULL) {
        current->next = q;
    }
    current->next = NULL; // 设置c链表的结尾指向NULL
    // 返回链表 c，其中的元素已经递增有序
    return c;
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


