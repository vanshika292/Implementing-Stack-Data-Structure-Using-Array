#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Task {
 char description[100];
 struct Task* next;
};
struct Task* front = NULL;
struct Task* rear = NULL;
void enqueue(const char* description);
void dequeue();
void displayQueue();
int main() {
 char choice;
 char description[100];
 printf("\n--------------------------------");
 printf("\nTO-DO LIST USING QUEUE");
 printf("\n--------------------------------");
 printf("\nOptions:\n");
 printf("1. Add Task\n");
 printf("2. Mark Task as Completed\n");
 printf("3. View To-Do List\n");
 printf("4. Exit\n");
 while (1) {
 printf("\nEnter your choice: ");
 scanf(" %c", &choice);
 switch (choice) {
 case '1':
 printf("Enter task description: ");
 scanf(" %[^\n]", description);
 enqueue(description);
 printf("\n\n");
 break;
 case '2':
 dequeue();
 break;
 case '3':
 displayQueue();
 break;
 case '4':
 printf("Program exited.\n");
 exit(0);
 default:
 printf("Invalid choice. Please try again.\n");
 }
 }
 return 0;
}
void enqueue(const char* description) {
 struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
 if (newTask == NULL) {
 printf("Memory allocation failed. Task addition failed.\n");
 return;
 }
 strncpy(newTask->description, description, sizeof(newTask->description));
 newTask->next = NULL;
 if (rear == NULL) {
 front = rear = newTask;
 } else {
 rear->next = newTask;
 rear = newTask;
 }
}
void dequeue() {
 if (front == NULL) {
 printf("To-Do List is empty. Nothing to mark as completed.\n");
 return;
 }
 struct Task* temp = front;
 front = front->next;
 printf("Marking task as completed: %s\n", temp->description);
 free(temp);
}
void displayQueue() {
 if (front == NULL) {
 printf("To-Do List is empty.\n");
 return;
 }
 struct Task* temp = front;
 printf("\nTo-Do List :\n");
 int count = 1;
 while (temp != NULL) {
 printf("%d. %s\n", count, temp->description);
 temp = temp->next;
 count++;
 }
}
