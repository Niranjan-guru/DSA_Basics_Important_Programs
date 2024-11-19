#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char stack[], char c) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = c;
    }
}

char pop(char stack[]) {
    if(top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int Precedence(char c) {
    if(c == '*' || c == '/' || c == '%') {
        return 2;
    } else if(c == '+' || c == '-') {
        return 1;
    } else {
        return 0;
    }
}

void InfixToPostfix(char source[], char target[]) {
    char temp;
    int i = 0, j = 0;

    while(source[i] != '\0' && source[i] != '\n') {  // Added check for newline character from fgets
        if(source[i] == '(') {
            push(stack, source[i]);
            i++;
        } else if(isalnum(source[i])) {
            target[j++] = source[i++];
        } else if(source[i] == ')') {
            while((top != -1) && (stack[top] != '(')) {
                target[j++] = pop(stack);
            }
            if(top == -1) {
                printf("Invalid Expression\n");
                return;
            }
            temp = pop(stack);  // Pop '('
            i++;
        } else if(source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%') {
            while((top != -1) && (stack[top] != '(') && (Precedence(stack[top]) >= Precedence(source[i]))) {
                target[j++] = pop(stack);
            }
            push(stack, source[i]);
            i++;
        } else {
            printf("Incorrect Expression\n");
            return;
        }
    }

    while((top != -1) && (stack[top] != '(')) {
        target[j++] = pop(stack);
    }

    target[j] = '\0';  // Null-terminate the target string

    if(top != -1 && stack[top] == '(') {  // Check for any remaining '('
        printf("Invalid Expression\n");
        return;
    }

    printf("The required Postfix Expression is: %s\n", target);
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter the Infix Expression: ");
    fgets(infix, MAX, stdin);
    strcpy(postfix, "");  // Initialize postfix as an empty string
    InfixToPostfix(infix, postfix);
    return 0;
}