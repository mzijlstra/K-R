#include <stdio.h>

#define STACK_SIZE 1024

char stack[STACK_SIZE];

int main() {
    int comment = 0;
    int character = 0;
    int string = 0;
    int line = 1;

    int pp = 0;
    int prev = 0;
    int i = 0;
    int c = 1;
    while ((pp = prev) && (prev = c) && (c = getchar()) != EOF) {
        /* close character, string and comment detection */
        if (character) {
            if (c == '\'' && prev != '\\' ||
                c == '\'' && prev == '\\' && pp == '\\') {
                printf("Stopping character on line %d\n", line);
                character = 0;
            }
            continue;
        }
        if (string) {
            if (c == '"' && prev != '\\') {
                printf("Stopping string on line %d\n", line);
                string = 0;
            }
            continue;
        }
        if (comment) {
            if (c == '/' && prev == '*') {
                printf("Stopping comment on line %d\n", line);
                comment = 0;
            }
            continue;
        }

        /* open character, string and comment detection */
        if (c == '\'') {
            printf("starting character on line %d\n", line);
            character = 1;
            continue;
        }
        if (c == '"') {
            printf("starting string on line %d\n", line);
            string = 1;
            continue;
        }
        if (c == '*' && prev == '/') {
            printf("starting comment on line %d\n", line);
            comment = 1;
            continue;
        }

        /* parentheses, brackets and braces */
        if (c == '(' || c == '[' || c == '{') {
            printf("Pushing %c on line %d\n", c, line);
            stack[i] = c;
            i++;
        } else if (c == ')') {
            if (stack[i - 1] != '(') {
                printf("Unbalanced parentheses\n");
                return 1;
            }
            printf("Popping %c on line %d\n", c, line);
            i--;
        } else if (c == ']') {
            if (stack[i - 1] != '[') {
                printf("Unbalanced square brackets\n");
                return 1;
            }
            printf("Popping %c on line %d\n", c, line);
            i--;
        } else if (c == '}') {
            if (stack[i - 1] != '{') {
                printf("Unbalanced curly braces\n");
                return 1;
            }
            printf("Popping %c on line %d\n", c, line);
            i--;
        }

        if (c == '\n') {
            line++;
        }
    }

    if (i != 0) {
        printf("Unbalanced, stack is:\n");
        for (int j = 0; j < i; ++j) {
            printf("%c", stack[j]);
        }
        printf("\n");
        return 1;
    }

    printf("Balanced parentheses, brackets and braces\n");
    return 0;
}
