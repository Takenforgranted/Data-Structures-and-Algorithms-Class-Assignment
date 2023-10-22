#ifndef SEQ_STACK_H
#define SEQ_STACK_H

#define maxsize 1024
typedef int datatype;
typedef struct
{
    datatype data[maxsize];
    int Top;
} SeqStack;

#endif // SEQ_STACK_H