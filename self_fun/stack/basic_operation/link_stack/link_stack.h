#ifndef LINK_STACK_H
#define LINK_STACK_H

typedef int datatype;

typedef struct node
{
    datatype data;
    struct node* next;
} StackNode;

typedef struct
{
    StackNode* Top;
} LinkStack;

#endif // LINK_STACK_H