#include <stdio.h>
int stack[50],choice,n,top,x,i;
void push(void);
void pop(void);
void peek(void);
void display(void);
int main()
{
top=-1;
printf("\nEnter the size of STACK (Max limit is 50):");
scanf("%d",&n);
printf("\n--------------------------------");
printf("\nSTACK OPERATIONS USING ARRAY");
printf("\n--------------------------------");
printf("\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT");
printf("\n--------------------------------");
do
{
 printf("\nEnter the Choice:");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 push();
 break;
 case 2:
 pop();
 break;
 case 3:
 peek();
 break;
 case 4:
 display();
 break;
 case 5:
 printf("\nEXIT POINT ");
 break;
 default:
 printf ("\nPlease Enter a Valid Choice out of 1,2,3,4");
 }
 }
while(choice!=5);
return 0;
}
//--------------------------P-U-S-H---------------------------------------------------
void push() {
 if(top>=n-1) {
 printf("\nSTACK is over flow");
 }
 else {
 printf("Enter a value to be pushed:");
 scanf("%d",&x);
 top++;
 stack[top]=x;
 }
}
//--------------------------P-O-P-----------------------------------------------------
void pop() {
 if(top<=-1) {
 printf("\nStack is under flow");
 }
 else {
 printf("The popped element is %d",stack[top]);
 printf("\n");
 top--;
 }
}
//-------------------------P-E-E-K----------------------------------------------------
void peek() {
 if(top<=-1) {
 printf("\nStack is under flow");
 }
 else {
 printf("The peeked element is %d",stack[top]);
 printf("\n");
 }
}
//----------------------D-I-S-P-L-A-Y-------------------------------------------------
void display() {
 if(top>=0) {
 printf("The elements in STACK are :");
 for(i=top; i>=0; i--)
 printf("\n%d",stack[i]);
 printf("\n");
 }
 else {
 printf("The STACK is empty");
 }
}
