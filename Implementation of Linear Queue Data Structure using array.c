#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
int front = -1, rear = -1;
int queue[MAX_SIZE];
int isFull() {
 return (rear == MAX_SIZE - 1);
}
int isEmpty() {
 return (front == -1);
}
void insert(int item) {
 if (isFull()) {
 printf("Queue is full. Cannot insert.\n");
 return;
 }
 if (front == -1)
 front = 0;
 rear++;
 queue[rear] = item;
 printf("%d inserted into the queue.\n", item);
}
int delete() {
 int item;
 if (isEmpty()) {
 printf("Queue is empty. Cannot delete.\n");
 return -1;
 }
 item = queue[front];
 if (front == rear)
 front = rear = -1;
 else
 front++;
 return item;
}
void display() {
 int i;
 if (isEmpty()) {
 printf("Queue is empty.\n");
 return;
 }
 printf("Queue elements: ");
 for (i = front; i <= rear; i++)
 printf("%d ", queue[i]);
 printf("\n");
}
int main() {
 int choice, item;
 printf("\n--------------------------------");
 printf("\nLINEAR QUEUE OPERATIONS USING ARRAY");
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
 printf("Exiting the program.\n");
 exit(0);
 default:
 printf("Please Enter a Valid Choice (1-4)\n");
 }
 }
 return 0;
}
