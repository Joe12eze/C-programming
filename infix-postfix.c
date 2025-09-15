#include <stdio.h>
#include <ctype.h>  // For isalnum()

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int main() {
    char infix[SIZE], postfix[SIZE];
    int i, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;  // Operand goes directly to postfix
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (peek() != '(')
                postfix[j++] = pop();
            pop();  // Pop the '('
        }
        else {  // Operator
            while (top != -1 && precedence(peek()) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';  // Null-terminate the postfix string

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

