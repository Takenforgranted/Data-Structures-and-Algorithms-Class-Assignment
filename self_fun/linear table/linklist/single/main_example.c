#include <stdio.h>
#include <stdlib.h>
#include "s_link.h"
#include "s_link_operation.h"

void printSeparator();

int main()
{
    s_linklist* L = InitSingleLinkedList();  // 初始化单链表

    if (L != NULL) {
        float initData[] = {1.2, 2.4, 3.6, 4.8, 5.2};  // 初始数据数组
        int initDataSize = sizeof(initData) / sizeof(initData[0]);
        ArrayToSingleLinkList(initData, initDataSize, L);

        int choice;
        while (1) {
            printSeparator();
            printf("Single Linked List Operations Menu\n");
            printf("1. Insert Element\n");
            printf("2. Delete Element\n");
            printf("3. Get Single Linked List Length\n");
            printf("4. Check if Single Linked List is Empty\n");
            printf("5. Print Single Linked List\n");
            printf("6. Find Element Position\n");
            printf("7. Get Element at a Specific Position\n");
            printf("8. Exit\n");
            printSeparator();
            printf("Please select an operation (1-8): ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    // 插入元素
                    printSeparator();
                    datatype x;
                    int InsertPosition;
                    printf("Please enter the element to insert: ");
                    scanf("%f", &x);
                    printf("Please enter the position to insert (starting from 1): ");
                    scanf("%d", &InsertPosition);
                    if (InsertLinkList(L, x, InsertPosition)) {
                        printf("Insertion successful!\n");
                    } else {
                        printf("Insertion failed.\n");
                    }
                    PrintLinkList(L);
                    break;
                case 2:
                    // 删除元素
                    printSeparator();
                    int deletePosition;
                    printf("Please enter the position to delete (starting from 1): ");
                    scanf("%d", &deletePosition);
                    if (DeleteLinkList(L, deletePosition)) {
                        printf("Deletion successful!\n");
                    } else {
                        printf("Deletion failed.\n");
                    }
                    PrintLinkList(L);
                    break;
                case 3:
                    // 获取单链表长度
                    printSeparator();
                    int length = JudgeSingleLinkListLength(L);
                    printf("The length of the single linked list is: %d\n", length);
                    PrintLinkList(L);
                    break;
                case 4:
                    // 判断单链表是否为空
                    printSeparator();
                    if (JudgeSingleLinkListEmpty(L)) {
                        printf("The single linked list is empty.\n");
                    } else {
                        printf("The single linked list is not empty.\n");
                        PrintLinkList(L);
                    }
                    break;
                case 5:
                    // 打印单链表内容
                    printSeparator();
                    PrintLinkList(L);
                    break;
                case 6:
                    // 查找元素位置
                    printSeparator();
                    datatype searchValue;
                    printf("Please enter the element to find: ");
                    scanf("%f", &searchValue);
                    int SearchPosition = LocateElemLinkList(L, searchValue);
                    if (SearchPosition != 0) {
                        printf("The position of element %.2f in the single linked list is: %d\n", searchValue, SearchPosition);
                        PrintLinkList(L);
                    } else {
                        printf("Element %.2f not found.\n", searchValue);
                    }
                    break;
                case 7:
                    // 获取指定位置的元素
                    printSeparator();
                    int getPosition;
                    printf("Please enter the position to get element from (starting from 1): ");
                    scanf("%d", &getPosition);
                    datatype element = GetElemLinkList(L, getPosition);
                    if (element != -1e9) {
                        printf("The element at position %d is: %.2f\n", getPosition, element);
                        PrintLinkList(L);
                    } else {
                        printf("Failed to get element, invalid position %d.\n", getPosition);
                    }
                    break;
                case 8:
                    // 退出程序
                    printSeparator();
                    DestroySingleLinkedList(L);
                    printf("Thank you for using the program. Goodbye!\n");
                    printSeparator();
                    exit(0);
                default:
                    printSeparator();
                    printf("Invalid operation option, please choose again.\n");
            }
        }
    } else {
        printf("Single linked list initialization failed.\n");
        printSeparator();
    }

    return 0;
}

void printSeparator()
{
    printf("=========================================\n");
}
