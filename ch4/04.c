#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <string.h> /* for strncmp() */

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char[]);
void push(double);
double pop(void);
void doCommand(char s[]);

/* reverse Polish calculator */
int main() {
    int type;
    double op1, op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0) {
                push(((int)pop()) % (int)op2);
            } else {
                printf("error: zero divisor\n");
            }
            break;
        case '!':
            doCommand(s);
            break;
        case '\n':
            op1 = pop();
            push(op1);
            printf("\t%.8g\n", op1);
            break;
        default:
            printf("error: unknown command %s type:%c \n", s, type);
            break;
        }
    }
    return 0;
}

#define MAXVAL 100  /* maximum depth of val stack */
int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can′t push %g\n", f);
}
/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void doCommand(char s[]) {
    double val, val2;
    if (strncmp(s, "print", MAXOP) == 0) {
        val = pop();
        push(val);
        printf("\t%.8g\n", val);
    } else if (strncmp(s, "dup", MAXOP) == 0) {
        val = pop();
        push(val);
        push(val);
        printf("Duplicated %.8g \n", val);
    } else if (strncmp(s, "swap", MAXOP) == 0) {
        val = pop();
        val2 = pop();
        push(val);
        push(val2);
        printf("Swapped %.8g and %.8g\n", val, val2);
    } else if (strncmp(s, "clear", MAXOP) == 0) {
        sp = 0;
        printf("Stack cleared\n");
    } else if (strncmp(s, "pop", MAXOP) == 0) {
        val = pop();
        printf("Popped %.8g off the stack\n", val);
    } else {
        printf("Unknown command, options are: print, dup, swap, clear, pop\n");
    }
}

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
/* s is an out parameter that can contain the number string or other operand */
int getop(char s[]) {
    int i, c, n;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    i = 0;
    if (c == '!') {
        // fill s with the command
        while ((s[i++] = c = getch()) >= 'a' && c <= 'z')
            ;
        s[i - 1] = '\0';
        return '!';
    }

    s[1] = '\0';

    if (c == '-') {
        n = getch();
        ungetch(n);
        if (!isdigit(n)) {
            return c; /* not a number, minus operator */
        }
    }

    if (!isdigit(c) && c != '.' && c != '-') {
        return c; /* not a number */
    }

    i = 0;
    if (c == '-' || isdigit(c)) { /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    if (c == '.') { /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
