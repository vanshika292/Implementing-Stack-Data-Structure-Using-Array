#include <stdio.h>
#include <stdlib.h>
struct Node {
 int data;
 struct Node* next;
};
struct Node* head = NULL;
void insert(int item);
void delete(int item);
void display();
void exitProgram();
int main() {
 int choice, item;
 printf("\n--------------------------------");
 printf("\nCIRCULAR SINGLY LINKED LIST");
 printf("\n--------------------------------");
 printf("\nOptions:\n");
 printf("1. Insert\n");
 printf("2. Delete\n");
 printf("3. Display\n");
 printf("4. Exit\n");
 while (1) {
 printf("Enter your choice : ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter a value to be inserted: ");
 scanf("%d", &item);
 insert(item);
 break;
 case 2:
 printf("Enter a value to be deleted: ");
 scanf("%d", &item);
 delete(item);
 break;
 case 3:
 display();
 break;
 case 4:
 exitProgram();
 break;
 default:
 printf("Invalid choice. Please try again.\n");
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
 newNode->next = head;
 if (head == NULL) {
 head = newNode;
 newNode->next = head;
 } else {
 struct Node* temp = head;
 while (temp->next != head) {
 temp = temp->next;
 }
 temp->next = newNode;
 }
 printf("%d inserted into the circular singly linked list.\n", item);
}
void delete(int item) {
 if (head == NULL) {
 printf("List is empty. Cannot delete.\n");
 return;
 }
 struct Node* current = head;
 struct Node* prev = NULL;
 do {
 if (current->data == item) {
 if (current == head) {
 struct Node* temp = head;
 while (temp->next != head) {
 temp = temp->next;
 }
 temp->next = head->next;
 head = head->next;
 free(current);
 printf("Deleted %d from the circular singly linked list.\n", item);
 return;
 } else {
 prev->next = current->next;
 free(current);
 printf("Deleted %d from the circular singly linked list.\n", item);
 return;
 }
 }
 prev = current;
 current = current->next;
 } while (current != head);
 printf("%d not found in the circular singly linked list.\n", item);
}
void display() {
 if (head == NULL) {
 printf("Circular singly linked list is empty.\n");
 return;
 }
 struct Node* current = head;
 printf("Circular singly linked list elements: ");
 do {
 printf("%d ", current->data);
 current = current->next;
 } while (current != head);
 printf("\n");
}
void exitProgram() {
 printf("Program exited.\n");
 exit(0);
}
