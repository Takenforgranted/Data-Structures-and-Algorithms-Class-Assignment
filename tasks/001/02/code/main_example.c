// 小心输出乱码！！！（GBK）
#include <stdio.h>
#include <stdlib.h>
#include "sequenlist.h"
#include "CMP_sqlist.h"

void printSeparator();

int main() {
    // 创建两个顺序表 A 和 B
    sequenlist* A = InitList();
    sequenlist* B = InitList();
    A->last = 5; // 设置 A 的长度为 5
    B->last = 5; // 设置 B 的长度为 5

    // 填充顺序表 A 和 B 的元素
    datatype arrayA[] = {1, 3, 5, 7, 9};
    datatype arrayB[] = {2, 4, 6, 8, 10};

    // 使用 ArrayToSequenList 函数将数组转换为顺序表
    ArrayToSequenList(arrayA, sizeof(arrayA) / sizeof(arrayA[0]), A);
    ArrayToSequenList(arrayB, sizeof(arrayB) / sizeof(arrayB[0]), B);

    // 调用 CMP_sqlist 函数比较 A 和 B
    int result = CMP_sqlist(A, B);

    // 根据比较结果输出相应的消息
    printSeparator();
    if (result == -1) {
        printf("result = %d：顺序表 A 在字典序上小于顺序表 B!!!\n", result);
    }
    else if (result == 1) {
        printf("result = %d：顺序表 A 在字典序上大于顺序表 B!!!\n", result);
    }
    else if (result == 0) {
        printf("result = %d：顺序表 A 和顺序表 B 在字典序上相等!!!\n", result);
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
