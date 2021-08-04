#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char str[100];

bool expn(int sta, int fin);
bool term(int sta, int fin);
bool fact(int sta, int fin);
bool id(int i);
bool num(int i);

int main(void)
{
    gets(str);
    int len = strlen(str);

    if(expn(0, len - 1))
        printf("Accepted by Grammar.\n");
    else
        printf("Rejected by Grammar.\n");

    return 0;
}

bool expn(int sta, int fin)
{
    int j = sta;
    int topB = -1;

    while(j < fin)
    {
        if((str[j] == '+' || str[j] == '-') && topB == -1)
            break;
        if(str[j] == '(')
            ++topB;
        else if(str[j] == ')')
            --topB;
        ++j;
    }

    if(j == fin)
        return term(sta, fin);
    else if((str[j] == '+' || str[j] == '-') && term(sta, j - 1))
        return term(j + 1, fin);
    else
        return false;
}

bool term(int sta, int fin)
{
    int j = sta;
    int topB = -1;

    while(j < fin)
    {
        if((str[j] == '*' || str[j] == '/') && topB == -1)
            break;
        if(str[j] == '(')
            ++topB;
        else if(str[j] == ')')
            --topB;
        ++j;
    }

    if(j == fin)
        return fact(sta, fin);
    else if((str[j] == '*' || str[j] == '/') && fact(sta, j - 1))
        return fact(j + 1, fin);
    else
        return false;
}

bool fact(int sta, int fin)
{
    if(id(sta) && sta == fin)
        return true;
    else if(num(sta) && sta == fin)
        return true;
    else if(str[sta] == '(' && str[fin] == ')')
        return expn(sta + 1, fin - 1);
    else
        return false;
}

bool id(int i)
{
    if(str[i] == 'a' || str[i] == 'b' || str[i] == 'c' || str[i] == 'd' || str[i] == 'e')
        return true;
    return false;
}

bool num(int i)
{
    if(isdigit(str[i]))
        return true;
    return false;
}
