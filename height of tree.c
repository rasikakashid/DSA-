#include <stdio.h> #include <stdlib.h> struct Node
{
int data;
struct Node *left, *right;
};
struct Node* createNode(int data)
{
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); newNode->data = data;
newNode->left = newNode->right = NULL; return newNode;
}
int height(struct Node* root)
{
if (root == NULL) return 0;
else
{
int leftHeight = height(root->left); int rightHeight = height(root->right); if (leftHeight > rightHeight)
return (leftHeight + 1);
 
else
return (rightHeight + 1);
}
}
int depth(struct Node* root, int key, int level)
{
if (root == NULL) return -1;
if (root->data == key) return level;
int left = depth(root->left, key, level + 1); if (left != -1)
return left;
return depth(root->right, key, level + 1);
}
int main()
{
struct Node* root = createNode(1); root->left = createNode(2);
root->right = createNode(3); root->left->left = createNode(4);
root->left->right = createNode(5); root->right->right = createNode(6);
printf("Height of the tree: %d\n", height(root)); int key = 5;
int d = depth(root, key, 0); if (d != -1)
 
printf("Depth of node %d: %d\n", key, d); else
printf("Node %d not found in the tree.\n", key); return 0;
}
