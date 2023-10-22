// С��������룡������GBK��
#include <stdio.h>
#include <stdlib.h>
#include "sequenlist.h"
#include "CMP_sqlist.h"

void printSeparator();

int main() {
    // ��������˳��� A �� B
    sequenlist* A = InitList();
    sequenlist* B = InitList();
    A->last = 5; // ���� A �ĳ���Ϊ 5
    B->last = 5; // ���� B �ĳ���Ϊ 5

    // ���˳��� A �� B ��Ԫ��
    datatype arrayA[] = {1, 3, 5, 7, 9};
    datatype arrayB[] = {2, 4, 6, 8, 10};

    // ʹ�� ArrayToSequenList ����������ת��Ϊ˳���
    ArrayToSequenList(arrayA, sizeof(arrayA) / sizeof(arrayA[0]), A);
    ArrayToSequenList(arrayB, sizeof(arrayB) / sizeof(arrayB[0]), B);

    // ���� CMP_sqlist �����Ƚ� A �� B
    int result = CMP_sqlist(A, B);

    // ���ݱȽϽ�������Ӧ����Ϣ
    printSeparator();
    if (result == -1) {
        printf("result = %d��˳��� A ���ֵ�����С��˳��� B!!!\n", result);
    }
    else if (result == 1) {
        printf("result = %d��˳��� A ���ֵ����ϴ���˳��� B!!!\n", result);
    }
    else if (result == 0) {
        printf("result = %d��˳��� A ��˳��� B ���ֵ��������!!!\n", result);
    }
    printSeparator();
    DestroyList(A);DestroyList(B);
    printf("Thank you for using the program. Goodbye!\n");
    printSeparator();

    return 0;
}

void printSeparator()
{
    printf("=========================================\n");
}
