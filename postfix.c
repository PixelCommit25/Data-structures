#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define BLANK ' '
#define TAB '\t'
#define MAX 50
void push(char symbol);
long int value;
long int pop();
long int eval_post();
void infix_to_postfix();
int priority(char symbol);
int IsEmpty();
int white_space(char);
char infix[MAX],postfix[MAX];
long int stack[MAX];
int top;

int main()
{
    long int vaue ;
    top=-1;
    printf("ENTER THE VALUE : ");
    gets(infix);
    infix_to_postfix();
    printf("POSTFIX  : %s \n",postfix);
    value=eval_post();
    printf("VALUE OF EXPRESSION : %ld \n",value);
    return 0;
}
void infix_to_postfix()
{
    unsigned int i,p=0;
    char next;
    char symbol;
    for(i=0; i<strlen(infix); i++)
    {
        symbol=infix[i];
        if(!white_space(symbol))
        {
            switch(symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':
                while((next=pop())!='(')
                    postfix[p++]=next;
                break;
            case '+':
            case '-':
            case '%':
            case '^':
            case '/':
            case '*':
                while(!IsEmpty() && priority(stack[top])>=priority(symbol))
                    postfix[p++]=pop();
                push(symbol);
                break;
            default:
                postfix[p++]=symbol;
            }
        }
    }
    while(!IsEmpty())
        postfix[p++]=pop();
    postfix[p]='\0';
}
int priority (char symbol)
{
    switch(symbol)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default :
        return 0;
    }
}
void push(char symbol)
{
    if(top>MAX)
    {
        printf("Stackoverflow\n ");
        exit(1);
    }
    stack[++top]=symbol;
}
long int pop()
{
    if(IsEmpty())
    {
        printf("Stack Underflow ");
        exit(1);
    }
    return (stack[top--]);
}
int IsEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int white_space(char symbol)
{
    if(symbol==BLANK || (symbol==TAB))
        return 1;
    else
        return 0;
}
long int eval_post()
{
    long int a,b,temp,result;
    unsigned int i;
    for(i=0; i<strlen(postfix); i++)
    {
        if(postfix[i]<='9'&& postfix[i]>='0')
            push(postfix[i]-'0');
            else
            {
                a=pop();
                b=pop();
                switch(postfix[i])
                {
                case '+':
                    temp=b+a;
                    break;
                case '-':
                    temp=b-a;
                    break;
                case '*':
                    temp=b*a;
                    break;
                case '/':
                    temp =b/a;
                    break;
                case '%':
                    temp=b%a;
                    break;
                case '^':
                    temp=pow(b,a);
                }
                push(temp);
            }
    }
    result=pop();
    return result;
}
