#include <stdio.h>
#include <stdlib.h>
struct Node {
 int data;
 struct Node* next;
};
struct Node* head = NULL;
void insert(int item);
void delete();
void display();
void exitProgram();
int main() {
 int choice, item;
 printf("\n--------------------------------");
 printf("\nSINGLY LINKED LIST OPERATIONS");
 printf("\n--------------------------------");
 printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
 printf("\n--------------------------------");
 while (1) {
 printf("\nEnter the Choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter a value to be inserted: ");
 scanf("%d", &item);
 insert(item);
 break;
 case 2:
 delete();
 break;
 case 3:
 display();
 break;
 case 4:
 exitProgram();
 break;
 default:
 printf("Please Enter a Valid Choice (1-4)\n");
 }
 }
 return 0;
}
void insert(int item) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 if (newNode == NULL) {
 printf("Memory allocation failed. Insertion failed.\n");
 return;
 }
 newNode->data = item;
 newNode->next = NULL;
 if (head == NULL) {
 head = newNode;
 } else {
 struct Node* temp = head;
 while (temp->next != NULL) {
 temp = temp->next;
 }
 temp->next = newNode;
 }
 printf("%d inserted into the linked list.\n", item);
}
void delete() {
 if (head == NULL) {
 printf("Linked list is empty. Cannot delete.\n");
 return;
 }
 struct Node* temp = head;
 head = head->next;
 free(temp);
 printf("Deleted the first node from the linked list.\n");
}
void display() {
 if (head == NULL) {
 printf("Linked list is empty.\n");
 return;
 }
 struct Node* temp = head;
 printf("Linked list elements: ");
 while (temp != NULL) {
 printf("%d ", temp->data);
 temp = temp->next;
 }
 printf("\n");
}
void exitProgram() {
 printf("Program exited.\n");
 exit(0);
}
