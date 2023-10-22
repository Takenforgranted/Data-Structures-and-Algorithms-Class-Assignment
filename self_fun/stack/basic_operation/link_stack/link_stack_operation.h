#include <stdlib.h>
#include <stdio.h>
#include "link_stack.h"

void InitStack(LinkStack*& S)
{
    S = (LinkStack*)malloc(sizeof(LinkStack));
    S->Top = NULL;
}

void SetNull(LinkStack* S)
{
    S->Top = NULL;
}

int Empty(LinkStack* S)
{
    return (S->Top == NULL);
}

void Push(LinkStack* S, datatype x)
{
    StackNode* p = (StackNode*)malloc(sizeof(StackNode));
    p->data = x;
    p->next = S->Top;
    S->Top = p;
}

int Pop(LinkStack* S, datatype& x)
{
    StackNode* p = S->Top;
    if (Empty(S)) {
        printf("Stack Underflow!!!");
        return 0;
    }
    else {
        x = p->data;
        S->Top = p->next;
        free(p);
        return 1;
    }
}

int GetTop(LinkStack* S, datatype& x)
{
    StackNode* p = S->Top;
    if (Empty(S)) {
        printf("Stack Underflow!!!");
        return 0;
    }
    else {
        x = p->data;
        return 1;
    }
}