/*
总体时间复杂度为O(max(m, n))，其中m和n分别是链表a和链表b的长度。
*/
#include <stdio.h>
#include <stdlib.h>
#include "s_link.h"
#include "MergeList.h"

void printSeparator();

int main()
{
    s_linklist* A = InitSingleLinkedList();
    s_linklist* B = InitSingleLinkedList();

    datatype arrayA[] = {3.7, 2.1, 1.9};
    datatype arrayB[] = {6.5, 5.3, 4.2};

    ArrayToSingleLinkList(arrayA, sizeof(arrayA) / sizeof(arrayA[0]), A);
    ArrayToSingleLinkList(arrayB, sizeof(arrayB) / sizeof(arrayB[0]), B);

    printf("链表A：\n");
    PrintLinkList(A);
    printf("链表B：\n");
    PrintLinkList(B);

    s_linklist* C = MergeLink(A, B);
    printSeparator();
    printf("合并后的链表C：\n");
    PrintLinkList(C);

    return 0;
}

void printSeparator() {
    printf("=========================================\n");
}