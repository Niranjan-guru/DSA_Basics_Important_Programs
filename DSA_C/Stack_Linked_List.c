#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* start = NULL;
struct Node* Push(struct Node* start);
struct Node* Pop(struct Node* start);
struct Node* Peek(struct Node* start);
struct Node* Display(struct Node* start);

int main() {
    int choice = 0; // Initialize choice
    while(choice != 5) {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                start = Push(start);
                break;
            case 2:
                start = Pop(start);
                break;
            case 3:
                start = Peek(start);
                break;
            case 4:
                start = Display(start);
                break;
            default:
                printf("Exiting...");
        }
    }
    return 0;
}

struct Node* Push(struct Node* start) {
    struct Node* new_node;
    int data;
    printf("Enter your data: ");
    scanf("%d", &data);
    new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if(start == NULL) {
        start = new_node;
    } else {
        new_node->next = start;
        start = new_node;
    }
    printf("Data %d has been successfully pushed!", start->data);
    return start;
}

struct Node* Pop(struct Node* start) {
    if(start == NULL) {
        printf("Stack is empty!\n");
        return start;
    }
    struct Node* ptr = start;
    start = start->next;
    printf("The value %d has been removed successfully!", ptr->data);
    free(ptr);
    return start;
}

struct Node* Peek(struct Node* start) {
    if(start == NULL) {
        printf("Stack is empty!\n");
    } else {
        printf("The top of the stack is: %d\n", start->data);
    }
    return start;
}

struct Node* Display(struct Node* start) {
    struct Node* ptr = start;
    printf("The current stack is: \n");
    while(ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    return start;
}
