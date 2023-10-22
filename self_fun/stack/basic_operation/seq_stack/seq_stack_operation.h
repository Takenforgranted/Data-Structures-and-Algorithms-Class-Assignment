#include <stdlib.h>
#include <stdio.h>
#include "seq_stack.h"

void InitStack(SeqStack*& S)
{
    S = (SeqStack*)malloc(sizeof(SeqStack));
    S->Top = -1;
}

void SetNull(SeqStack* S)
{
    S->Top = -1;
}

int Empty(SeqStack* S)
{
    if (S->Top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int Push(SeqStack* S, datatype x)
{
    if (S->Top == maxsize - 1) {
        printf("Stack Overflow!!!");
        return 0;
    }
    else {
        S->data[++S->Top] = x;
        return 1;
    }
}

int Pop(SeqStack* S, datatype& x)
{
    if (Empty(S)) {
        printf("Stack Underflow!!!");
        return 0;
    }
    else {
        x = S->data[S->Top--];
        return 1;
    }
}

int GetTop(SeqStack* S, datatype& x)
{
    if (Empty(S)) {
        printf("Stack Underflow!!!");
        return 0;
    }
    else {
        x = S->data[S->Top];
        return 1;
    }
}