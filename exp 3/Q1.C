#include <stdio.h>
#include <stdlib.h> 

int *stack;    
int top = -1; 
int size;      

void push();
void pop();
void display();

int main() {
    int choice;

    printf("Enter the capacity of the stack: ");
    scanf("%d", &size);

    stack = (int *)malloc(size * sizeof(int));

    if (stack == NULL) {
        printf("Memory allocation failed! Exiting...");
        return 1;
    }

    while (1) {
        printf("\n--- Stack (Capacity: %d) ---", size);
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push();size--; break;
            case 2: pop();size++; break;
            case 3: display(); break;
            case 4: 
                free(stack); 
                exit(0);
            default: printf("Invalid choice!");
        }
    }
    return 0;
}

void push() {
    int value;
    if (top == size - 1) {
        printf("Stack Overflow!\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("Pushed %d\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
    } else {
        printf("Popped: %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (Top to Bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
