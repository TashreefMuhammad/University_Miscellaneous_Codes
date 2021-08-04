/**
ab=c>d
if(a==b) c=d else d=c
for(a=0;a<e;a=3) b=c
while(a<e) b=c
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char str[100];

bool stat(int sta, int fin);
bool asgn_stat(int sta, int fin);
bool idnt(int sta, int fin);
bool dscn_stat(int sta, int fin);
bool loop_stat(int sta, int fin);
bool expn(int sta, int fin);
bool smpl_expn(int sta, int fin);
bool extn(int sta, int fin);
int relop(int sta);
bool extn1(int sta, int fin);

bool term(int sta, int fin);
bool fact(int sta, int fin);
bool id(int i);
bool num(int i);

int main(void)
{
    gets(str);
    int len = strlen(str);

    if(stat(0, len - 1))
        printf("Accepted by Grammar.\n");
    else
        printf("Rejected by Grammar.\n");

    return 0;
}

bool stat(int sta, int fin)
{
    if(asgn_stat(sta, fin))
        return true;
    else if(dscn_stat(sta, fin))
        return true;
    else if(loop_stat(sta, fin))
        return true;
    else
        return false;
}

bool asgn_stat(int sta, int fin)
{
    int j = sta;

    while(j <= fin && str[j] != '=')
        ++j;
    if(j == fin)
        return false;
    else if(str[j] == '=')
        return (idnt(sta, j-1) && expn(j + 1, fin));
    else
        return false;
}

bool dscn_stat(int sta, int fin)
{
    int j, k;
    if(str[sta] == 'i' && str[sta + 1] == 'f' && str[sta + 2] == '(')
    {
        j = sta + 3;

        while(str[j] != ')')
            ++j;

        if(expn(sta + 3, j - 1))
        {
            j += 2;
            k = j;

            while(j < fin && str[j] != ' ')
                ++j;
            if(j == fin)
                return stat(k, j);
            else if(stat(k, j-1))
                return extn1(j + 1, fin);
        }
        return false;
    }
    return false;
}

bool loop_stat(int sta, int fin)
{
    char ch[4];
    ch[0] = str[sta];
    ch[1] = str[sta + 1];
    ch[2] = str[sta + 2];
    ch[3] = '\0';

    int j, k;
    if(str[sta] = 'w' && str[sta + 1] == 'h' && str[sta + 2] == 'i' && str[sta + 3] == 'l' && str[sta + 4] == 'e')
    {
        j = sta + 5;

        if(str[j] == '(')
        {
            ++j;
            k = j;

            while(j <= fin && str[j] != ')')
                ++j;

            if(expn(k, j-1))
            {
                j += 2;
                return stat(j, fin);
            }
            else
                return false;
        }
        return false;
    }

    if(!strcmp(ch, "for"))
    {
        j = sta + 3;

        if(str[j] == '(')
        {
            ++j;
            k = j;

            while(j <= fin && str[j] != ';')
                ++j;

            if(asgn_stat(k, j-1))
            {
                ++j;
                k = j;

                while(j <= fin && str[j] != ';')
                ++j;
                if(expn(k, j-1))
                {
                    ++j;
                    k = j;

                    while(j <= fin && str[j] != ')')
                        ++j;
                    if(asgn_stat(k, j-1))
                        return stat(j + 2, fin);
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    return false;
}

bool expn(int sta, int fin)
{
    int j = sta;

    while(j < fin && !relop(j))
        ++j;

    if(j == fin)
        return smpl_expn(sta, fin);
    else if(smpl_expn(sta, j - 1) && extn(j, fin))
            return true;
    else
        return false;
}

bool idnt(int sta, int fin)
{
    if(isalpha(str[sta]) || str[sta] == '_')
    {
        int j = sta + 1;

        while(j <= fin)
        {
            if(!isalnum(str[j]) && str[j] != '_')
                break;
            ++j;
        }

        if(j == fin + 1)
            return true;
        return false;
    }
    return false;
}

bool extn(int sta, int fin)
{
    int val = relop(sta);
    if(val == 1 && smpl_expn(sta+2, fin))
        return true;
    else if(val == 2 && smpl_expn(sta+1, fin))
        return true;
    return false;
}

int relop(int sta)
{
    char ch[3];
    ch[0] = str[sta];
    ch[1] = str[sta + 1];
    ch[2] = '\0';

    if(!strcmp(ch, "==") || !strcmp(ch, "!=") || !strcmp(ch, "<=") || !strcmp(ch, ">="))
        return 1;
    else if(ch[0] == '>' || ch[0] == '<')
        return 2;
    return 0;
}

bool extn1(int sta, int fin)
{
    if(str[sta] == 'e' && str[sta + 1] == 'l' && str[sta + 2] == 's' && str[sta + 3] == 'e' && str[sta + 4] == ' ')
        return stat(sta + 5, fin);
    return false;
}

bool smpl_expn(int sta, int fin)
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
