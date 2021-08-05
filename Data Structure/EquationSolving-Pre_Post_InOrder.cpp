
#include <stdio.h>
#include <string.h>

void push(char c);
void pop();
void emptystack();
void pushorpop(char c);
void sumofpostfix(int l);
void result(char c);

int j,top,number_stack[100];
char expression_stack[100],postfix_expression[100],infix_expression[100];

int main(void)
{
    int l,i;
    char choice,op;
    printf("Enter an Infix Expression -> ");
    scanf("%s",&infix_expression);
    l=strlen(infix_expression);
    i=j=0;
    top=-1;
    while(i<l)
    {
        choice = infix_expression[i];
        if(choice >= '0' && choice <='9')
        {
            op=choice;
            choice='n';
        }
        else if(choice == '+' || choice == '-' || choice == '*' || choice == '/')
        {
            op=choice;
            choice='o';
        }
        switch(choice)
        {
            case '(': push(choice);
                    break;
            case ')': pop();
                    break;
            case 'n': postfix_expression[j]=op;
                    j++;
                    break;
            case 'o': pushorpop(op);
                    break;
            default: printf("Invalid Choice character provided.");
                    break;
        }
        i++;
    }
    emptystack();
    postfix_expression[j]='\0';
    l=strlen(postfix_expression);
    printf("Postfix Expression-> %s",postfix_expression);
    sumofpostfix(l);
    printf("\nEvaluate:\n\tEvaluated value of Postfix: %d",number_stack[top]);
    return 0;
}

void push(char c)
{
    top++;
    expression_stack[top]=c;
}

void pop()
{
    while(expression_stack[top]!='(')
    {
        postfix_expression[j]=expression_stack[top];
        j++;
        top--;
    }
    top--;
}

void emptystack()
{
    while(top!=-1)
    {
        postfix_expression[j]=expression_stack[top];
        j++;
        top--;
    }
}

void pushorpop(char c)
{
    if(c=='/')
        while(top!=-1 && expression_stack[top]=='/' && expression_stack[top]!='(')
        {
            postfix_expression[j]=expression_stack[top];
            j++;
            top--;
        }
    else if(c=='*')
        while(top!=-1 && (expression_stack[top]=='/' && expression_stack[top]=='*') && expression_stack[top]!='(')
        {
            postfix_expression[j]=expression_stack[top];
            j++;
            top--;
        }
    else
        while(top!=-1 && (expression_stack[top]=='/' && expression_stack[top]=='*' || expression_stack[top]!='+' && expression_stack[top]!='-') && expression_stack[top]!='(')
        {
            postfix_expression[j]=expression_stack[top];
            j++;
            top--;
        }
    top++;
    expression_stack[top]=c;
}

void sumofpostfix(int l)
{
    int i;
    top=-1;
    char e,op;
    for(i=0;i<l;i++)
    {
        e=postfix_expression[i];
        if(e>='0'&&e<='9')
        {
            op=e;
            e='o';
        }
        switch(e)
        {
            case 'o': top++;
                    number_stack[top]=postfix_expression[i]-'0';
                    break;
            default: result(e);
                    break;
        }
    }
}

void result(char c)
{
    int var2,var1;
    var2=number_stack[top];
    top--;
    var1=number_stack[top];
    if(c=='+')
        number_stack[top]=var1+var2;
    else if(c=='-')
        number_stack[top]=var1-var2;
    else if(c=='*')
        number_stack[top]=var1*var2;
    else
        number_stack[top]=var1/var2;
}
