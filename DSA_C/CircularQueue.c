#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;
void enqueue();
void dequeue();
void display();
void peek();

//Driver code
int main(){
    int option;
    do{
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\nEnter your choice: ");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        }
    }while(option!=5);
    return 0;
}

void enqueue(){
    int value;
    printf("Enter the value; ");
    scanf("%d",&value);
    if(front==0 && rear == MAX-1){
        printf("Queue Overflow\n");
    }
    else{
        if(front==-1 && rear==-1){
            front = rear = 0;
        }
        else if(front!=0 && rear==MAX-1){
            rear = 0;
        }
        else{
            rear++;
        }
        queue[rear] = value;
    }
}

void dequeue(){
    int val;
    if(front==-1){
        printf("Queue Underflow\n");
    }
    else{
        int val = queue[front];
        printf("The value removed is %d",val);
        if(front==rear){
            front=rear=-1;
        }
        else if(front==MAX-1){
            front=0;
        }
        else{
            front++;
        }
    }
}

void display(){
    int i;
    if(front==-1){
        printf("Queue Underflow\n");
    }
    else{
        if(front<=rear){
            for(i = front;i<=rear; i++){
                printf("%d\n",queue[i]);
            }
        }
        else{
            for(i = front;i<MAX;i++){
                printf("%d\n",queue[i]);
            }
            for(i = 0; i<=rear; i++){
                printf("%d\n",queue[i]);
            }
        }
    }
}

void peek(){
    if(front==-1){
        printf("Queue Underflow\n");
    }
    else{
        printf("%d <-- rear",queue[rear]);
    }
}