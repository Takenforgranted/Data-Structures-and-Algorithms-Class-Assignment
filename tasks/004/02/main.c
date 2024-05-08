#include <stdio.h>
#include <stdlib.h>

// 树的节点结构
struct TreeNode {
    char data;  // 节点数据
    struct TreeNode* left;  // 左子节点
    struct TreeNode* right; // 右子节点
};

// 创建一个新的树节点
struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 将满二叉树转换为树或森林
struct TreeNode* convertToTree(struct TreeNode* root, int value, int depth) {
    if (depth == 0) {
        return NULL;
    }
    root = createNode('A' + value - 1);
    // 递归创建左子树和右子树
    root->left = convertToTree(root->left, 2 * value, depth - 1);
    root->right = convertToTree(root->right, 2 * value + 1, depth - 1);

    return root;
}

// 打印树的先序遍历结果
void printPreorder(struct TreeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;
    // 将深度为4的满二叉树转换为树
    root = convertToTree(root, 1, 4);
    // 打印树的先序遍历结果
    printf("Preorder Traversal of the Tree:\n");
    printPreorder(root);

    return 0;
}
