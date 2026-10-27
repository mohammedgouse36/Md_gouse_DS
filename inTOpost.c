#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define SIZE 50

char stack[SIZE];
int top = -1;


void push(char elem)
{
    stack[++top] = elem;
}

char pop()
{
    return stack[top--];
}

int pr(char symbol)
{
    if(symbol == '^')
    {
        return 3;
    }
    else if(symbol == '*' || symbol == '/')
    {
        return 2;
    }
    else if(symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


double evaluatePostfix(char postfix[], double values[])
{
    double evalStack[SIZE];
    int evalTop = -1;
    int i;
    char ch;
    double a, b;

    for(i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        if(isalpha(ch))
        {
            evalStack[++evalTop] = values[toupper(ch) - 'A'];
        }


        else if(isdigit(ch))
        {
            evalStack[++evalTop] = ch - '0';
        }


        else
        {
            b = evalStack[evalTop--];
            a = evalStack[evalTop--];

            switch(ch)
            {
                case '+':
                    evalStack[++evalTop] = a + b;
                    break;

                case '-':
                    evalStack[++evalTop] = a - b;
                    break;

                case '*':
                    evalStack[++evalTop] = a * b;
                    break;

                case '/':
                    evalStack[++evalTop] = a / b;
                    break;

                case '^':
                    evalStack[++evalTop] = pow(a, b);
                    break;
            }
        }
    }

    return evalStack[evalTop];
}


/* Main Program */
void main()
{
    char infix[50], postfix[50], ch, elem;
    double values[26] = {0};
    double result;

    int i = 0, k = 0;
    int j, alreadyAsked;

    printf("Enter Infix Expression : ");
    scanf("%s", infix);



    push('#');

    while((ch = infix[i++]) != '\0')
    {
        if(ch == '(')
        {
            push(ch);
        }
        else
        {
            if(isalnum(ch))
            {
                postfix[k++] = ch;
            }
            else
            {
                if(ch == ')')
                {
                    while(stack[top] != '(')
                    {
                        postfix[k++] = pop();
                    }

                    elem = pop();
                }
                else
                {

                    while(pr(stack[top]) >= pr(ch))
                    {
                        postfix[k++] = pop();
                    }

                    push(ch);
                }
            }
        }
    }



    while(stack[top] != '#')
    {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("\nPostfix Expression = %s\n", postfix);




    printf("\nEnter values for variables:\n");

    for(i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if(isalpha(ch))
        {
            ch = toupper(ch);

            alreadyAsked = 0;


            for(j = 0; j < i; j++)
            {
                if(toupper(infix[j]) == ch)
                {
                    alreadyAsked = 1;
                    break;
                }
            }

            if(!alreadyAsked)
            {
                printf("%c = ", ch);
                scanf("%lf", &values[ch - 'A']);
            }
        }
    }


    result = evaluatePostfix(postfix, values);

    printf("\nResult = %.2lf\n", result);
}
