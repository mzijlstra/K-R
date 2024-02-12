#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>/* for atof() */

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char[]);
void push(double);
double pop(void);
void clear(void);

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
        case '$': /* sin */
            push(sin(pop()));
            break;
        case '^': /* pow */
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case 'c': /* clear stack */
            clear();
            break;
        case 'd': /* duplicate top element */
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 'e': /* exp */
            push(exp(pop()));
            break;
        case 'p': /* pop top element */
            printf("\t%.8g\n", pop());
            break;
        case 'q': /* quit program */
            goto end;
        case 'r': /* print top element */
        case '\n':
            op2 = pop();
            push(op2);
            printf("\t%.8g\n", op2);
            break;
        case 's': /* swap top 2 elements */
            op2 = pop();
            op1 = pop();
            push(op2);
            push(op1);
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
end:
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
/* clear: reset the stack pointer to quickly clear stack */
void clear(void) {
    sp = 0;
    printf("stack cleared\n");
}

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    int i, c, n;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    /* remove newline for letter commands */
    if (c >= 'a' && c <= 'z') {
        n = getch();
        if (n == '\n') {
            return c;
        }
    }

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
