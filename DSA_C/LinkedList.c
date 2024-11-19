#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* start = NULL;

struct Node* Insert_Beginning(struct Node* start){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    int value;
    printf("Enter the data to insert: ");
    scanf("%d",&value);
    newNode->data = value;

    if(start == NULL){
        newNode->next = NULL;
        start = newNode;
    }
    else{
        newNode->next = start;
        start = newNode;
    }
    return start;
}

struct Node* Insert_End(struct Node* start){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    int data;
    printf("Enter the data to insert: ");
    scanf("%d",&data);
    newNode->data = data;
    if(start == NULL){
        newNode->next = NULL;
        start = newNode;
    }
    else{
        struct Node* ptr = start;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->next = NULL;
    }
    return start;
}

void display(){
    struct Node* ptr = start;
    if(ptr == NULL){
        printf("List is Empty\n");
    }
    else{
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

int main(){
    int choice;
    while(choice!=4){
        printf("1.Insert at Beginning\n2.Insert at End\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
              start = Insert_Beginning(start);
              break;
            case 2:
              start = Insert_End(start);
              break;
            case 3:
              display();
              break;
            default:
              printf("Exiting...\n");
        }
    }
    return 0;
}