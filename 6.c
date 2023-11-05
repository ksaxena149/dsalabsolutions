// Implement a Program in C for converting an Infix Expression to a Postfix Expression and Prefix expression. The program should support both parenthesized and free parenthesized expressions with the operators: +, -, *, /, 
// %(Remainder), ^(Power) and alphanumeric operands.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

char peek(struct Stack* stack) {
    return stack->items[stack->top];
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}

int precedence(char operator) {
    if (operator == '^')
        return 3;
    else if (operator == '*' || operator == '/' || operator == '%')
        return 2;
    else if (operator == '+' || operator == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack operatorStack;
    initialize(&operatorStack);
    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        char currentSymbol = infix[i];
        if (isalnum(currentSymbol)) {
            postfix[j++] = currentSymbol;
        } else if (currentSymbol == '(') {
            push(&operatorStack, currentSymbol);
        } else if (currentSymbol == ')') {
            while (!isEmpty(&operatorStack) && peek(&operatorStack) != '(') {
                postfix[j++] = pop(&operatorStack);
            }
            if (!isEmpty(&operatorStack) && peek(&operatorStack) != '(') {
                printf("Invalid expression: Mismatched parentheses\n");
                exit(EXIT_FAILURE);
            } else {
                pop(&operatorStack);
            }
        } else if (isOperator(currentSymbol)) {
            while (!isEmpty(&operatorStack) && precedence(currentSymbol) <= precedence(peek(&operatorStack))) {
                postfix[j++] = pop(&operatorStack);
            }
            push(&operatorStack, currentSymbol);
        }
        i++;
    }

    while (!isEmpty(&operatorStack)) {
        postfix[j++] = pop(&operatorStack);
    }

    postfix[j] = '\0';
}

void infixToPrefix(char infix[], char prefix[]) {
    struct Stack operatorStack;
    initialize(&operatorStack);
    int i, j;
    i = j = 0;

    int len = strlen(infix);
    // Reverse the infix expression
    for (i = len - 1; i >= 0; i--) {
        char currentSymbol = infix[i];
        if (isalnum(currentSymbol)) {
            prefix[j++] = currentSymbol;
        } else if (currentSymbol == ')') {
            push(&operatorStack, currentSymbol);
        } else if (currentSymbol == '(') {
            while (!isEmpty(&operatorStack) && peek(&operatorStack) != ')') {
                prefix[j++] = pop(&operatorStack);
            }
            if (!isEmpty(&operatorStack) && peek(&operatorStack) != ')') {
                printf("Invalid expression: Mismatched parentheses\n");
                exit(EXIT_FAILURE);
            } else {
                pop(&operatorStack); // Pop the ')'
            }
        } else if (isOperator(currentSymbol)) {
            while (!isEmpty(&operatorStack) && precedence(currentSymbol) < precedence(peek(&operatorStack))) {
                prefix[j++] = pop(&operatorStack);
            }
            push(&operatorStack, currentSymbol);
        }
    }

    while (!isEmpty(&operatorStack)) {
        prefix[j++] = pop(&operatorStack);
    }

    // Reverse the prefix expression
    char reversedPrefix[MAX_SIZE];
    for (i = j - 1; i >= 0; i--) {
        reversedPrefix[j - i - 1] = prefix[i];
    }
    reversedPrefix[j] = '\0';
    strcpy(prefix, reversedPrefix);
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression %s\n", postfix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
