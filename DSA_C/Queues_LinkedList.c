#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Queue{
    struct Node* front;
    struct Node* rear;
};

void create_queue(struct Queue* q);
struct Queue* Enqueue(struct Queue* q);
struct Queue* Dequeue(struct Queue* q);
struct Queue* Peek(struct Queue* q);
struct Queue* Display(struct Queue* q);

int main(){
    int option;
    struct Queue* q;
    q = (struct Queue*)malloc(sizeof(struct Queue));
    create_queue(q);
    do{
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\nEnter your choice: ");
        scanf("%d",&option);
        switch (option)
        {
            case 1:
              q = Enqueue(q);
              break;
            case 2:
              q = Dequeue(q);
              break;
            case 3:
              q = Peek(q);
              break;
            case 4:
              q = Display(q);
              break;
        }
    }while(option!=5);
    free(q);
    return 0;    
}
void create_queue(struct Queue* q){
    q->front = NULL;
    q->rear = NULL;
}
struct Queue* Enqueue(struct Queue* q){
    int val;
    struct Node* new_node;
    new_node = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter a data: ");
    scanf("%d",&val);
    new_node->data = val;
    new_node->next = NULL;
    if(q->front == NULL && q->rear==NULL){
        q->front = new_node;
        q->rear = new_node;
    }
    else{
        q->rear->next = new_node;
        q->rear = new_node;
    }
    return q;
}
struct Queue* Dequeue(struct Queue* q){
    struct Node* ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    if(q->front==NULL){
        printf("Queue Underflow\n");
    }
    else{
        ptr = q->front;
        q->front = q->front->next;
        printf("The value %d is removed\n",ptr->data);
        free(ptr);
    }
    return q;
}
struct Queue* Peek(struct Queue* q){
    if(q->front==NULL){
        printf("Queue Empty\n");
    }
    else{
        printf("The rear most value is ---> %d",q->rear->data);
    }
    return q;
}
struct Queue* Display(struct Queue* q){
    struct Node* ptr;
    ptr = q->front;
    if(ptr == NULL){
        printf("Queue Empty\n");
    }
    else{
        while(ptr!=q->rear){
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
        printf("%d",ptr->data);
    }
    return q;
}
