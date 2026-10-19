#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char ch) { stack[++top] = ch; }
char pop(void) { return stack[top--]; }
char peek(void) { return stack[top]; }

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main(void) {
    char infix[100], postfix[100];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum((unsigned char)ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top >= 0 && peek() != '(')
                postfix[j++] = pop();
            if (top >= 0 && peek() == '(') pop();
        } else {
            while (top >= 0 && peek() != '(' &&
                   (precedence(peek()) > precedence(ch) ||
                   (precedence(peek()) == precedence(ch) && ch != '^'))) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top >= 0) postfix[j++] = pop();
    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
