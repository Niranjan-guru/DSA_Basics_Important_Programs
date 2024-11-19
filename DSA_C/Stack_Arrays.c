#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int Stack[MAX];
int top = -1;
void Push(int data){
    if(top==MAX-1){
        printf("Stack Overflow");
    }
    Stack[++top] = data;
    printf("The value %d is pushed into the stack",data);
}

void Pop(){
    if(top==-1){
        printf("Stack Underflow");
    }
    printf("The value %d is removed",Stack[top]);
    Stack[top--];
}

int Peek(){
    return Stack[top];
}

void Display(){
    int i;
    if(top==-1){
        printf("Stack Empty");
    }
    for(i=0;i<=top;i++){
        printf("%d\t",Stack[i]);
    }
}

int main(){
    int choice = 0;
    while(choice!=5){
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
              if(top==MAX-1){
                printf("Stack Overflow");
                break;
              }
              int value;
              printf("Enter a data to push: ");
              scanf("%d",&value);
              Push(value);
              break;
            case 2:
               if(top==-1){
                printf("Stack Underflow");
                break;
               }
               Pop();
               break;
            case 3:
               if(top==-1){
                printf("Stack Empty");
                break;
               }  
               int res = Peek();
               printf("%d <-- top",res);
               break;
            case 4:
               if(top==-1){
                printf("Stack Empty!");
                break;
               }
               Display();
               break;
            case 5:
               printf("Exiting...");
               break;
            default:
               printf("Enter the correct Option");
        }
    }
    return 0;
}