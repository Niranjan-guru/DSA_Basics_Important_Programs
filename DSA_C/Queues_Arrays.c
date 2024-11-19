#include<stdio.h>
#define MAX 100

int queues[MAX];
int front = -1,rear = -1;
void Enqueue();
int Dequeue();
void Display();
int Peek();

int main(){
    int option,value;
    do{
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Exit\nEnter your choice: ");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            Enqueue();
            break;
        case 2:
            value = Dequeue();
            if(value==1){
                printf("The value deleted is %d",value);
                break;
            }
            else{
                printf("Cannot delete any value!");
                break;
            }
        case 3:
            Display();
            break;
        case 4:
            value = Peek();
            printf("The rear most value is ---> %d",value);
            break;
        }
    }while(option!=5);
    return 0;
}

void Enqueue(){
    int data;
    printf("Enter the data: ");
    scanf("%d",&data);
    if(front==-1 && rear == -1){
        front=rear=0;
        queues[front] = data;
    }
    else if(rear==MAX-1){
        printf("Queue Overflow\n");
    }
    else{
        rear = rear+1;
        queues[rear] = data;
    }
}

int Dequeue(){
    if(front==-1 || front>rear){
        printf("Queue Underflow\n");
        return 0;
    }
    else{
        return queues[rear--];
    }
}

void Display(){
    int i;
    for(i=front; i<=rear; i++){
        printf("%d\n",queues[i]);
    }
}

int Peek(){
    return queues[rear];
}