#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coeff;
    int pow;
    struct Node* next;
};

struct Node* start1 = NULL,start2 = NULL,start3 = NULL;

struct Node* create_polynomial(struct Node* start){
    struct Node* newNode,ptr;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    ptr = start;
    int c,n;
    printf("Enter the coefficient and its power: ");
    scanf("%d %d",&n,&c);
    while(n!=-1){
        if(start != NULL){
            newNode->coeff = n;
            newNode->pow = c;
            newNode->next = NULL;
            start = newNode;
        }
        else{
            ptr = start;
            while(ptr->next!=NULL){
                ptr = ptr->next;
            }
            newNode->coeff = n;
            newNode->pow = c;
            newNode->next = NULL;
            ptr->next = newNode;
        }
    }
    return start;
}

struct Node* display(struct Node* start){
    struct Node* ptr = start;
    while(ptr!+NULL){
        printf("%dx^(%d)\t",ptr->coeff,ptr->pow);
        ptr = ptr->next;
    }
    return start;
}

struct Node* add_Node(struct Node* start, int n, int c){
    struct Node* ptr=start;
    if(start == NULL){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = n;
        newNode->pow = c;
        newNode->next = NULL;
        start = newNode;
    }
    else{
        while(ptr->next!= NULL){
            ptr = ptr->next;
        }
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = n;
        newNode->pow = c;
        newNode->next = NULL;
        ptr->next = newNode;    
    }
}

struct Node* add_polynomial(struct Node* start1, struct Node* start2, struct Node* start3){
    struct Node* ptr1 = start1, ptr2 = start2;
    int add_poly;
    while(ptr1!=NULL & ptr2!= NULL){
        if(ptr1->pow == ptr2->pow){
            add_poly = ptr1->coeff + ptr2->coeff;
            start3 = add_Node(start3, add_poly, ptr1->pow);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->pow > ptr2->pow){
            start3 = add_Node(start3, ptr1->coeff, ptr1->pow);
            ptr1 = ptr1->next;
        }
        else if(ptr1->pow < ptr2->pow){
            start3 = add_Node(start3, ptr2->coeff, ptr2->pow);
        }
    }
    if(ptr1 == NULL){
        while(ptr2!= NULL){
            start3 = add_Node(start3, ptr2->coeff, ptr2->pow);
            ptr2 = ptr2->next;
        }
    }
    else if(ptr2 == NULL){
        while(ptr1!=NULL){
            start3 = add_Node(start3, ptr1->coeff, ptr1->pow);
            ptr1 = ptr1->next;
        }
    }
    return start3;
}