#include <ctype.h>
#include <math.h> /* for sin, exp, pow */
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <string.h> /* for strncmp() */

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define ALPHAS 26

int getop(char[]);
void push(double);
double pop(void);
void doCommand(char s[]);
double getVar(char s[]);
void setVar(char s[], double val);
void ungets(char s[], int n);

double last = 0; /* holds most recently printed value */
double vars[ALPHAS];

/* reverse Polish calculator */
int main() {
    /* test the ungets functionality */
    ungets("4 5 +", 5);
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
        case '$':
            push(getVar(s));
            break;
        case '=':
            setVar(s, pop());
            break;
        case '!':
            doCommand(s);
            break;
        case '\n':
            printf("\t%.8g\n", pop());
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
    if (sp > 0) {
        last = val[--sp];
        return last;
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double getVar(char s[]) {
    if (s[0] == '_') {
        printf("Getting last printed value\n");
        return last;
    }
    printf("Getting %c\n", s[0]);
    return vars[s[0] - 'a'];
}

void setVar(char s[], double val) {
    vars[s[0] - 'a'] = val;
    printf("Setting %c to %.8g\n", s[0], val);
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
    } else if (strncmp(s, "sin", MAXOP) == 0) {
        val = pop();
        val2 = sin(val);
        push(val2);
        printf("sin(%.8g) is %.8g\n", val, val2);
    } else if (strncmp(s, "exp", MAXOP) == 0) {
        val = pop();
        val2 = exp(val);
        push(val2);
        printf("exp(%.8g) is %.8g\n", val, val2);
    } else if (strncmp(s, "pow", MAXOP) == 0) {
        val = pop();
        val2 = pop();
        double val3 = pow(val2, val);
        printf("pow(%.8g, %.8g) is %.8g\n", val2, val, val3);
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

    if (c == '$' || c == '=') {
        s[0] = getch();
        s[1] = '\0';
        return c;
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

/* ungets should just use ungetch */
void ungets(char s[], int n) {
    int i = 0;
    while (s[i] != '\0' && i < n) {
        i++;
    }
    i--;
    while (i >= 0) {
        ungetch(s[i]);
        i--;
    }
}
