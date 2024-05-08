#include <stdio.h>
#include <stdlib.h>

// 定义树节点结构
struct TreeNode {
    int data;
    struct TreeNode* first_child; // 指向第一个孩子节点
    struct TreeNode* next_sibling; // 指向右兄弟节点
};

// 创建新节点的函数
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->first_child = NULL;
    newNode->next_sibling = NULL;
    return newNode;
}

// 递归计算树的深度
int treeDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        // 递归计算左子树的深度
        int leftDepth = treeDepth(root->first_child);
        // 递归计算右兄弟树的深度
        int rightDepth = treeDepth(root->next_sibling);
        // 返回较大的深度加1（加1是因为当前节点也算一层）
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}

int main() {
    // 构建一个树
    struct TreeNode* root = createNode(1);
    root->first_child = createNode(2);
    root->first_child->next_sibling = createNode(3);
    root->first_child->next_sibling->next_sibling = createNode(4);
    root->first_child->next_sibling->next_sibling->first_child = createNode(5);
    
    // 计算树的深度
    int depth = treeDepth(root);
    printf("The depth of tree: %d\n", depth);
    
    return 0;
}
