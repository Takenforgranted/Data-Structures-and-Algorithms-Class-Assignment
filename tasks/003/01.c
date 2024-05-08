#include <stdio.h>
#include <stdlib.h>

// 定义单链表节点
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// 逆置一个单链表
Node* ReverseLinkedList(Node* head) {
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;  // 新的头节点
}

// 查找并逆置S中首次与T匹配的子串
void ReverseFirstMatchedSubstring(Node** S, Node* T) {
    Node* sCurrent = *S;
    Node* tCurrent = T;
    Node* matchStart = NULL;
    Node* prevNode = NULL;
    while (sCurrent != NULL) {
        if (sCurrent->data == tCurrent->data) {
            if (tCurrent == T) {
                matchStart = sCurrent; // 记录匹配的起始位置
            }
            tCurrent = tCurrent->next;
        } else {
            tCurrent = T;
            matchStart = NULL;
        }
        if (tCurrent == NULL) { // T全部匹配
            // 逆置匹配的子串
            Node* matchEnd = sCurrent;
            Node* nextNode = sCurrent->next;
            if (matchStart != NULL) {
                matchEnd->next = NULL;
                if (*S == matchStart) {
                    *S = ReverseLinkedList(matchStart);
                } else {
                    prevNode->next = ReverseLinkedList(matchStart);
                }
                matchStart->next = nextNode;
                break;
            }
        }
        prevNode = sCurrent;
        sCurrent = sCurrent->next;
    }
}

// 打印单链表
void PrintList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 将字符串转换为单链表
Node* StringToLinkedList(const char* str) {
    Node* head = NULL;  // 链表头指针
    Node* tail = NULL;  // 链表尾指针
    for (int i = 0; str[i] != '\0'; i++) {
        // 创建新节点
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = str[i];
        newNode->next = NULL;
        if (head == NULL) {
            // 如果链表为空，设置头指针和尾指针为新节点
            head = newNode;
            tail = newNode;
        } else {
            // 否则，将新节点连接到链表末尾，并更新尾指针
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

int main() {
    char S_input[100];
    char T_input[100];
    printf("Enter the content for S: ");
    scanf("%s", S_input);
    printf("Enter the content for T: ");
    scanf("%s", T_input);
    Node* S = StringToLinkedList(S_input);
    Node* T = StringToLinkedList(T_input);
    printf("Original S: ");
    PrintList(S);
    printf("Original T: ");
    PrintList(T);
    ReverseFirstMatchedSubstring(&S, T);
    printf("Modified S: ");
    PrintList(S);
    // 释放内存
    while (S != NULL) {
        Node* temp = S;
        S = S->next;
        free(temp);
    }
    while (T != NULL) {
        Node* temp = T;
        T = T->next;
        free(temp);
    }
    printf("Thanks for using!!!\n");

    return 0;
}