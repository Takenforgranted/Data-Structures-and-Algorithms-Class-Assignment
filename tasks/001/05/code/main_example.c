#include <stdio.h>
#include <stdlib.h>
#include "s_link.h"
#include "DeleteList.h"

void printSeparator();

int main()
{
    printf("DeleteList算法的时间复杂度为O(n)!!!\n");
    printSeparator();
    // 创建并初始化单向链表 L
    s_linklist* L = InitSingleLinkedList();
    datatype min = 3.0;
    datatype max = 6.0;
    // 填充链表 L 的元素
    datatype arrayL[] = {1.5, 2.7, 3.2, 4.8, 5.6, 6.9, 7.1};
    ArrayToSingleLinkList(arrayL, sizeof(arrayL) / sizeof(arrayL[0]), L);

    // 打印初始链表内容
    printf("初始链表内容：\n");
    PrintLinkList(L);

    // 调用 DeleteList 函数，删除数据范围在 [3.0, 6.0] 内的元素
    DeleteList(L, min, max);

    // 打印删除元素后的链表内容
    printSeparator();
    printf("删除数据范围在 [%.1f, %.1f] 内的元素后的链表内容：\n", min, max);
    PrintLinkList(L);

    printSeparator();
    printf("感谢使用程序。再见!\n");
    printSeparator();

    return 0;
}

void printSeparator() {
    printf("=========================================\n");
}
