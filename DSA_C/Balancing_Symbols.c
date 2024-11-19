#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 10 

int top = -1;
char stack[MAX];

void push(char c){
    if(top == MAX-1){
        printf("Overflow\n");
    }
    stack[++top] = c;
}
char pop(){
    if(top == -1){
        printf("Stack Underflow\n");
    }
    else{
        return stack[top--];
    }
}

int main(){
    char expression[MAX], temp;
    printf("Enter the expression to check: ");
    fgets(expression,MAX,stdin);
    int i,flag=1;
    for(i=0;i<strlen(expression);i++){
        if(expression[i] == '[' || expression[i] == '{' || expression[i] == '('){
            push(expression[i]);
        }
        else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']'){
            if(top == -1){
                flag = 0;
            }
            else{
                temp = pop();
                if((expression[i] == ')') && (temp == '{' || temp == '[')){
                    flag = 0;
                }else if((expression[i] == ']') && (temp == '{' || temp == '(')){
                    flag = 0;
                }else if((expression[i] == '}') && (temp == '(' || temp == '[')){
                    flag = 0;
                }
            }
        }
    }
    if(top >= 0){
        flag = 0;
    }
    if(flag == 1){
        printf("\n Valid Expression");
    }
    else{
        printf("\n Invalid Expression");
    }
    return 0;
}