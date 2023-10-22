/*
����ʱ�临�Ӷ�ΪO(max(m, n))������m��n�ֱ�������a������b�ĳ��ȡ�
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

    printf("����A��\n");
    PrintLinkList(A);
    printf("����B��\n");
    PrintLinkList(B);

    s_linklist* C = MergeLink(A, B);
    printSeparator();
    printf("�ϲ��������C��\n");
    PrintLinkList(C);

    return 0;
}

void printSeparator() {
    printf("=========================================\n");
}