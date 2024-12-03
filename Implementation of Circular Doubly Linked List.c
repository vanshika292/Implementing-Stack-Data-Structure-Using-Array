#include <stdio.h>
#include <stdlib.h>
struct Node {
 int data;
 struct Node* next;
 struct Node* prev;
};
struct Node* head = NULL;
void insert(int item);
void delete(int item);
void display();
void exitProgram();
int main() {
 int choice, item;
 printf("\n--------------------------------");
 printf("\nCIRCULAR DOUBLY LINKED LIST");
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
 if (head == NULL) {
 newNode->next = newNode;
 newNode->prev = newNode;
 head = newNode;
 } else {
 struct Node* tail = head->prev;
 tail->next = newNode;
 newNode->prev = tail;
 newNode->next = head;
 head->prev = newNode;
 }
 printf("%d inserted into the circular doubly linked list.\n", item);
}
void delete(int item) {
 if (head == NULL) {
 printf("List is empty. Cannot delete.\n");
 return;
 }
 struct Node* current = head;
 do {
 if (current->data == item) {
 if (current == head) {
 if (head->next == head) {
 free(head);
head = NULL;
 } else {
 struct Node* tail = head->prev;
 head = head->next;
 tail->next = head;
 head->prev = tail;
 free(current);
 }
 printf("Deleted %d from the circular doubly linked list.\n", item);
 return;
 } else {
 current->prev->next = current->next;
 current->next->prev = current->prev;
 free(current);
 printf("Deleted %d from the circular doubly linked list.\n", item);
 return;
 }
 }
 current = current->next;
 } while (current != head);
 printf("%d not found in the circular doubly linked list.\n", item);
}
void display() {
 if (head == NULL) {
 printf("Circular doubly linked list is empty.\n");
 return;
 }
 struct Node* current = head;
 printf("Circular doubly linked list elements (forward): ");
 do {
 printf("%d ", current->data);
 current = current->next;
 } while (current != head);
 printf("\n");
 current = head->prev;
 printf("Circular doubly linked list elements (backward): ");
 do {
 printf("%d ", current->data);
 current = current->prev;
 } while (current != head->prev);
 printf("\n");
}
void exitProgram() {
 printf("Program exited.\n");
 exit(0);
}
