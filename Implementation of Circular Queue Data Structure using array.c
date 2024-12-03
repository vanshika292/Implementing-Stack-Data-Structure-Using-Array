#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
int front = -1, rear = -1;
int queue[MAX_SIZE];
void insert(int item);
int delete();
void display();
void exitProgram();
int main() {
 int choice, item;
 printf("\n--------------------------------");
 printf("\nCIRCULAR QUEUE OPERATIONS USING ARRAY");
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
 item = delete();
 if (item != -1)
 printf("Deleted element: %d\n", item);
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
 if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
 printf("Queue is full. Cannot insert.\n");
 return;
 }
 if (front == -1)
 front = rear = 0;
 else {
 if (rear == MAX_SIZE - 1)
 rear = 0;
 else
 rear++;
 }
 queue[rear] = item;
 printf("%d inserted into the queue.\n", item);
}
int delete() {
 int item;
 if (front == -1) {
 printf("Queue is empty. Cannot delete.\n");
 return -1;
 }
 item = queue[front];
 if (front == rear)
 front = rear = -1;
 else {
 if (front == MAX_SIZE - 1)
 front = 0;
 else
 front++;
 }
 return item;
}
void display() {
 int i;
 if (front == -1) {
 printf("Queue is empty.\n");
 return;
 }
 printf("Queue elements: ");
 if (rear >= front) {
 for (i = front; i <= rear; i++)
 printf("%d ", queue[i]);
 } else {
 for (i = front; i < MAX_SIZE; i++)
 printf("%d ", queue[i]);
 for (i = 0; i <= rear; i++)
 printf("%d ", queue[i]);
 }
 printf("\n");
}
void exitProgram() {
 printf("Exiting the program.\n");
 exit(0);
}
