#include <stdlib.h>
#include <stdio.h>
#include "s_link.h"

s_node* InitSingleNode();

s_linklist* InitSingleLinkedList();

void DestroySingleNode(s_node* node);

void DestroySingleLinkedList(s_linklist* L);

int JudgeSingleLinkListEmpty(const s_linklist* L);

int JudgeSingleLinkListLength(const s_linklist* L);

void ArrayToSingleLinkList(datatype a[], int size, s_linklist* L);

void PrintLinkList(const s_linklist* L);

datatype GetElemLinkList(const s_linklist* L, int i);

int LocateElemLinkList(const s_linklist* L, datatype e);

int InsertLinkList(s_linklist* L, datatype x, int i);

int DeleteLinkList(s_linklist* L, int i);

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

    L->head = NULL;  // 初始化头结点指针为NULL
    return L;
}

/**
 * @brief 销毁单链表结点
 *
 * 该函数用于销毁一个单链表结点，并释放其所占用的内存。
 *
 * @param node 指向要销毁的结点的指针
 *
 * @return 无返回值
 */
void DestroySingleNode(s_node* node)
{
    if (node != NULL) {  // 检查结点指针是否为NULL
        free(node);      // 释放结点占用的内存
    }
}

/**
 * @brief 销毁单链表
 *
 * 该函数用于销毁一个单链表，包括销毁链表中的所有结点，并释放相应的内存。
 *
 * @param list 指向要销毁的单链表的指针
 *
 * @return 无返回值
 */
void DestroySingleLinkedList(s_linklist* L)
{
    if (L != NULL) {  // 检查链表指针是否为NULL
        s_node* current = L->head;
        while (current != NULL) {
            s_node* temp = current;
            current = current->next;
            DestroySingleNode(temp);  // 销毁每个结点并防备野指针
        }
        free(L);  // 释放链表结构的内存
    }
}


/**
 * 判断单向链表是否为空
 *
 * 该函数用于判断单向链表是否为空，即链表中是否包含任何结点。
 *
 * @param head 指向单向链表的头指针
 * @return 当链表为空时返回1，否则返回0
 */
int JudgeSingleLinkListEmpty(const s_linklist* L)
{
    return L->head == NULL;  // 若链表的头指针指向NULL，表示链表为空，返回1；否则返回0
}


/**
 * @brief 判断单向链表的长度
 *
 * 该函数用于计算单向链表的长度，即链表中包含的节点数目。
 *
 * @param L 指向要计算长度的单向链表
 * @return 返回链表的节点数量
 */
int JudgeSingleLinkListLength(const s_linklist* L)
{
    int count = 0;   // 初始化节点计数器为0
    s_node* current = L->head;  // 从链表头节点开始遍历

    while (current != NULL) {
        count++;                // 增加节点计数
        current = current->next;  // 移动到下一个节点
    }

    return count;  // 返回链表的节点数量
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
            L->head = new_node;
            current = new_node;
        }
        else {
            current->next = new_node;  // 连接新结点到当前结点的下一个
            current = new_node;  // 更新当前结点为新结点
        }
    }
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
    if (L->head == NULL) {
        printf("Empty!!!\n");
    }
    else {
        s_node* current = L->head;  // 从链表头节点开始
        while (current != NULL) {
            printf("%.2f ", current->data);  // 打印当前结点的数据
            current = current->next;  // 移动到下一个结点
        }
        printf("\n");
    }
}


/**
 * @brief 获取单向链表指定位置的元素
 *
 * 该函数用于获取单向链表中指定位置的元素。
 *
 * @param L 指向要获取元素的单向链表的指针
 * @param i 要获取的元素的位置（从1开始计数）
 *
 * @return 返回获取到的元素的值，如果位置无效或链表为空，则返回特殊值-1e9表示错误。
 */
datatype GetElemLinkList(const s_linklist* L, int i)
{
    if (i < 1 || L->head == NULL) {
        printf("Error - Illegal Read Position!!!");
        return -1e9;  // 返回一个表示错误的特殊值
    }
    else {
        s_node* current = L->head;  // 从链表头节点开始
        int count = 1;  // 初始化计数器为1

        // 遍历链表直到找到指定位置的元素或到达链表末尾
        while (current != NULL && count < i) {
            current = current->next;  // 移动到下一个结点
            count++;  // 增加计数器
        }

        if (current == NULL) {
            printf("Error - Position out of range!!!");
            return -1e9;  // 返回一个表示错误的特殊值
        }
        else {
            return current->data;  // 返回指定位置的元素值
        }
    }
}


/**
 * @brief 寻找第一个与给定元素相等的元素位置
 *
 * 该函数用于在单向链表中寻找第一个与给定元素 `e` 相等的元素的位置。
 *
 * @param L 指向单向链表的指针，指向要操作的链表
 * @param e 要寻找的元素的值
 * @return 返回第一个与 `e` 相等的元素的位置（从1开始计数），如果未找到则返回0表示未找到
 */
int LocateElemLinkList(const s_linklist* L, datatype e)
{
    if (L->head == NULL) {
        return 0;  // 链表为空，返回0表示未找到
    }

    s_node* current = L->head;  // 从链表头节点开始
    int position = 1;  // 初始化位置计数器为1

    // 遍历链表，查找第一个与给定元素相等的元素
    while (current != NULL) {
        if (current->data == e) {
            return position;  // 返回元素位置（从1开始计数）
        }

        current = current->next;  // 移动到下一个结点
        position++;  // 增加位置计数器
    }

    return 0;  // 未找到与 `e` 相等的元素，返回0表示未找到
}


/**
 * @brief 在单链表中插入元素
 *
 * 该函数用于在单链表的指定位置插入一个元素。
 *
 * @param L 指向单链表的指针，指向要插入元素的链表
 * @param x 待插入的元素值
 * @param i 插入位置的索引，从1开始计数
 * @return 操作是否成功，成功返回1，失败返回0
 */
int InsertLinkList(s_linklist* L, datatype x, int i)
{
    if (i < 1 || L->head == NULL) {
        printf("Error - Illegal Insert Position or Empty List!!!");
        return 0;
    }
    else {
        s_node* current = L->head;
        s_node* previous = NULL;
        int position = 1;

        s_node* new_node = InitSingleNode();
        if (new_node == NULL) {
            printf("Error - Memory allocation failed.");
            return 0;
        }
        new_node->data = x;  // 设置新结点的数据

        // 遍历链表找到插入位置
        while (current != NULL && position < i) {
            previous = current;
            current = current->next;
            position++;
        }

        // 如果插入位置是链表头
        if (position == 1) {
            new_node->next = L->head;
            L->head = new_node;
        }
        // 否则，在指定位置插入新元素
        else {
            previous->next = new_node;
            new_node->next = current;
        }

        return 1;
    }
}

/**
 * @brief 在单链表中删除元素
 *
 * 该函数用于从单链表中删除指定位置的元素。
 *
 * @param L 指向单链表的指针，指向要删除元素的链表
 * @param i 删除位置的索引，从1开始计数
 * @return 操作是否成功，成功返回1，失败返回0
 */
int DeleteLinkList(s_linklist* L, int i)
{
    if (i < 1 || L->head == NULL) {
        printf("Error - Illegal Delete Position or Empty List!!!");
        return 0;
    }
    else {
        s_node* current = L->head;
        s_node* previous = NULL;
        int position = 1;

        // 遍历链表找到删除位置
        while (current != NULL && position < i) {
            previous = current;
            current = current->next;
            position++;
        }

        // 如果删除位置是链表头
        if (position == 1) {
            L->head = current->next;
            DestroySingleNode(current);  // 销毁被删除的结点
        }
        // 否则，在指定位置删除元素
        else {
            previous->next = current->next;
            DestroySingleNode(current);  // 销毁被删除的结点
        }

        return 1;
    }
}
