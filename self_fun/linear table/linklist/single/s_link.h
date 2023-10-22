#ifndef S_LINK_H
#define S_LINK_H

typedef float datatype;

typedef struct single_node
{
    datatype data;
    struct single_node* next;
} s_node;

typedef struct single_linklist
{
    s_node* head;  // 指向链表的头节点
} s_linklist;

#endif // S_LINK_H