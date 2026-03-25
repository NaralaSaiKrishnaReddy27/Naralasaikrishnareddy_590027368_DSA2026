#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char* infix, char* postfix) {
    int i, j = 0;
    char symbol;

    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        } 
        else if (symbol == '(') {
            push(symbol);
        } 
        else if (symbol == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        } 
        else if (isOperator(symbol)) {
            while (top != -1 && precedence(peek()) >= precedence(symbol)) {
                if (symbol == '^' && peek() == '^') break; 
                postfix[j++] = pop();
            }
            push(symbol);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[] = "A+B*(C^D-E)^(F+G*H)-I";
    char postfix[MAX];

    printf("Infix Expression: %s\n", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
