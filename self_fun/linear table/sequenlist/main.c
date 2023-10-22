#include <stdio.h>
#include <stdlib.h>
#include "sequenlist.h"
#include "sequenlist_operation.h"


void printSeparator();


int main()
{
    sequenlist* L = InitList();  // 初始化顺序表 (Initialize the sequence list)
    if (L != NULL) {
        float initData[] = { 1.2, 2.4, 3.6, 4.8, 5.2 };  // 初始数据数组 (Initial data array)
        int initDataSize = sizeof(initData) / sizeof(initData[0]);
        ArrayToSequenList(initData, initDataSize, L);
        int choice;
        while (1) {
            printSeparator();
            printf("Sequence List Operations Menu\n");
            printf("1. Insert Element\n");
            printf("2. Delete Element\n");
            printf("3. Get Sequence List Length\n");
            printf("4. Check if Sequence List is Empty\n");
            printf("5. Print Sequence List\n");
            printf("6. Find Element Position\n");
            printf("7. Get Element at a Specific Position\n");
            printf("8. Exit\n");
            printSeparator();
            printf("Please select an operation (1-8): ");
            scanf("%d", &choice);

            switch (choice) {
            case 1:
                // 插入元素 (Insert Element)
                printSeparator();
                datatype x;
                int InsertPosition;
                printf("Please enter the element to insert: ");
                scanf("%f", &x);
                printf("Please enter the position to insert (starting from 1): ");
                scanf("%d", &InsertPosition);
                if (InsertList(L, x, InsertPosition)) {
                    printf("Insertion successful!\n");
                }
                else {
                    printf("Insertion failed.\n");
                }
                PrintList(L);
                break;
            case 2:
                // 删除元素 (Delete Element)
                printSeparator();
                int deletePosition;
                printf("Please enter the position to delete (starting from 1): ");
                scanf("%d", &deletePosition);
                if (DeleteList(L, deletePosition)) {
                    printf("Deletion successful!\n");
                }
                else {
                    printf("Deletion failed.\n");
                }
                PrintList(L);
                break;
            case 3:
                // 获取顺序表长度 (Get Sequence List Length)
                printSeparator();
                int length = JudgeListLength(L);
                printf("The length of the sequence list is: %d\n", length);
                PrintList(L);
                break;
            case 4:
                // 判断顺序表是否为空 (Check if Sequence List is Empty)
                printSeparator();
                if (JudgeListEmpty(L)) {
                    printf("The sequence list is empty.\n");
                }
                else {
                    printf("The sequence list is not empty.\n");
                    PrintList(L);
                }
                
                break;
            case 5:
                // 打印顺序表内容 (Print Sequence List)
                printSeparator();
                PrintList(L);
                break;
            case 6:
                // 查找元素位置 (Find Element Position)
                printSeparator();
                datatype searchValue;
                printf("Please enter the element to find: ");
                scanf("%f", &searchValue);
                int SearchPosition = LocateElemList(L, searchValue);
                if (SearchPosition != 0) {
                    printf("The position of element %f in the sequence list is: %d\n", searchValue, SearchPosition);
                    PrintList(L);
                }
                else {
                    printf("Element %f not found.\n", searchValue);
                }

                break;
            case 7:
                // 获取指定位置的元素 (Get Element at a Specific Position)
                printSeparator();
                int getPosition;
                printf("Please enter the position to get element from (starting from 1): ");
                scanf("%d", &getPosition);
                int element = GetElemList(L, getPosition);
                if (element != -1e9) {
                    printf("The element at position %d is: %d\n", getPosition, element);
                    PrintList(L);
                }
                else {
                    printf("Failed to get element, invalid position %d.\n", getPosition);
                }
                break;
            case 8:
                // 退出程序 (Exit the program)
                printSeparator();
                DestroyList(L);
                printf("Thank you for using the program. Goodbye!\n");
                printSeparator();
                exit(0);
            default:
                printSeparator();
                printf("Invalid operation option, please choose again.\n");
            }
        }
    }
    else {
        printf("Sequence list initialization failed, what are you f**king doing!!!\n");
        printSeparator();
    }
    
    return 0;
}

void printSeparator()
{
    printf("=========================================\n");
}

