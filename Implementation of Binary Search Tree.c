#include <stdio.h>
#include <stdlib.h>
// Define a structure for a node in the BST
struct Node {
 int data;
 struct Node* left;
 struct Node* right;
};
// Function prototypes
struct Node* createNode(int item);
struct Node* insert(struct Node* root, int item);
struct Node* search(struct Node* root, int item);
void inorderTraversal(struct Node* root);
void preorderTraversal(struct Node* root);
void postorderTraversal(struct Node* root);
struct Node* deleteNode(struct Node* root, int item);
int main() {
 struct Node* root = NULL;
 int choice, item;
 printf("\n--------------------------------");
 printf("\nBINARY SEARCH TREE (BST)");
 printf("\n--------------------------------");
 printf("\nOptions:\n");
 printf("1. Insert\n");
 printf("2. Search\n");
 printf("3. Inorder Traversal\n");
 printf("4. Preorder Traversal\n");
 printf("5. Postorder Traversal\n");
 printf("6. Delete\n");
 printf("7. Exit\n");
 while (1) {
 printf("Enter your choice (1/2/3/4/5/6/7): ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter a value to insert: ");
 scanf("%d", &item);
 root = insert(root, item);
 break;
 case 2:
 printf("Enter a value to search: ");
 scanf("%d", &item);
 if (search(root, item) != NULL) {
 printf("%d found in the BST.\n", item);
 } else {
 printf("%d not found in the BST.\n", item);
 }
 break;
 case 3:
 printf("Inorder Traversal: ");
 inorderTraversal(root);
 printf("\n");
 break;
 case 4:
 printf("Preorder Traversal: ");
 preorderTraversal(root);
 printf("\n");
 break;
 case 5:
 printf("Postorder Traversal: ");
 postorderTraversal(root);
 printf("\n");
 break;
 case 6:
 printf("Enter a value to delete: ");
 scanf("%d", &item);
 root = deleteNode(root, item);
 break;
 case 7:
 printf("Exiting the program.\n");
 exit(0);
 default:
 printf("Invalid choice. Please try again.\n");
 }
 }
 return 0;
}
// Function to create a new node with the given data
struct Node* createNode(int item) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 if (newNode == NULL) {
 printf("Memory allocation failed. Node creation failed.\n");
 return NULL;
 }
 newNode->data = item;
 newNode->left = NULL;
 newNode->right = NULL;
 return newNode;
}
// Function to insert a node into the BST
struct Node* insert(struct Node* root, int item) {
 if (root == NULL) {
 return createNode(item);
 }
 if (item < root->data) {
 root->left = insert(root->left, item);
 } else if (item > root->data) {
 root->right = insert(root->right, item);
 }
 return root;
}
// Function to search for a node with the given data in the BST
struct Node* search(struct Node* root, int item) {
 if (root == NULL || root->data == item) {
 return root;
 }
 if (item < root->data) {
 return search(root->left, item);
 }
 return search(root->right, item);
}
// Function to perform an inorder traversal of the BST
void inorderTraversal(struct Node* root) {
 if (root == NULL) {
 return;
 }
 inorderTraversal(root->left);
 printf("%d ", root->data);
 inorderTraversal(root->right);
}
// Function to perform a preorder traversal of the BST
void preorderTraversal(struct Node* root) {
 if (root == NULL) {
 return;
 }
 printf("%d ", root->data);
 preorderTraversal(root->left);
 preorderTraversal(root->right);
}
// Function to perform a postorder traversal of the BST
void postorderTraversal(struct Node* root) {
 if (root == NULL) {
 return;
 }
 postorderTraversal(root->left);
 postorderTraversal(root->right);
 printf("%d ", root->data);
}
// Function to delete a node with the given data from the BST
struct Node* deleteNode(struct Node* root, int item) {
 if (root == NULL) {
 return root;
 }
 if (item < root->data) {
 root->left = deleteNode(root->left, item);
 } else if (item > root->data) {
 root->right = deleteNode(root->right, item);
 } else {
 if (root->left == NULL) {
 struct Node* temp = root->right;
 free(root);
 return temp;
 } else if (root->right == NULL) {
 struct Node* temp = root->left;
 free(root);
 return temp;
 }
 struct Node* temp = root->right;
 while (temp->left != NULL) {
 temp = temp->left;
 }
 root->data = temp->data;
 root->right = deleteNode(root->right, temp->data);
 }
 return root;
}
