#include <stdio.h>
#include <stdlib.h>
#include "s_link.h"
#include "DeleteList.h"

void printSeparator();

int main()
{
    printf("DeleteList�㷨��ʱ�临�Ӷ�ΪO(n)!!!\n");
    printSeparator();
    // ��������ʼ���������� L
    s_linklist* L = InitSingleLinkedList();
    datatype min = 3.0;
    datatype max = 6.0;
    // ������� L ��Ԫ��
    datatype arrayL[] = {1.5, 2.7, 3.2, 4.8, 5.6, 6.9, 7.1};
    ArrayToSingleLinkList(arrayL, sizeof(arrayL) / sizeof(arrayL[0]), L);

    // ��ӡ��ʼ��������
    printf("��ʼ�������ݣ�\n");
    PrintLinkList(L);

    // ���� DeleteList ������ɾ�����ݷ�Χ�� [3.0, 6.0] �ڵ�Ԫ��
    DeleteList(L, min, max);

    // ��ӡɾ��Ԫ�غ����������
    printSeparator();
    printf("ɾ�����ݷ�Χ�� [%.1f, %.1f] �ڵ�Ԫ�غ���������ݣ�\n", min, max);
    PrintLinkList(L);

    printSeparator();
    printf("��лʹ�ó����ټ�!\n");
    printSeparator();

    return 0;
}

void printSeparator() {
    printf("=========================================\n");
}
