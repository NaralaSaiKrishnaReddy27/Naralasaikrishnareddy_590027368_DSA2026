#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) return;
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

int isMatchingPair(char left, char right) {
    if (left == '(' && right == ')') return 1;
    if (left == '{' && right == '}') return 1;
    if (left == '[' && right == ']') return 1;
    return 0;
}

int isBalanced(char* exp) {
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) return 0;
            
            char topChar = pop();
            if (!isMatchingPair(topChar, exp[i])) {
                return 0; 
            }
        }
    }
    
    return (top == -1);
}

int main() {
    char exp[MAX];

    printf("Enter an expression: ");
    scanf("%s", exp);

    if (isBalanced(exp)) {
        printf("The expression is Balanced.\n");
    } else {
        printf("The expression is NOT Balanced.\n");
    }

    return 0;
}

