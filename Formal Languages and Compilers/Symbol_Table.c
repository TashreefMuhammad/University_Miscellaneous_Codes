#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define N 10000

typedef struct table table;

struct table
{
    int id;
    char name[100], iT[100], dT[100], sc[100], val[100];
} tabVal[100];

char check[100], cur[100], dType[100][50], scope[100][50];
int cnt, iType, topD, topS;

void stepOne();
void stepTwo();

void tabInsert();
void tabUpdate(int ind);
void tabDelete();
void tabSearch();
void tabDisplay();
void scopeVal();

int main(void)
{
    topD = topS = -1;
    stepOne();
    stepTwo();
    int i;

    for(i = 0; i < cnt; ++i)
        printf("%d\t|\t%s\t|\t%s\t|\t%s\t|\t%s\t|\t%s\n", tabVal[i].id, tabVal[i].name, tabVal[i].iT, tabVal[i].dT, tabVal[i].sc, tabVal[i].val);

    return 0;
}

void stepOne()
{
    FILE *inFile, *oneFile;
    int i, len, left = 0, right = 0;
    char str[N];

    inFile = fopen("input.txt", "r");
    oneFile = fopen("stepOne.txt", "w");

    if(!inFile)
        printf("No File Available.\n");

    else
    {
        while(fgets(str, N-1, inFile))
        {
            for(i = 0; i < N-1; ++i)
            {
                if(ferror(inFile) || feof(inFile))
                    break;
                if(str[i] == '[')
                {
                    fprintf(oneFile, "[");
                    ++i;
                    if(str[i] == 'i')
                    {
                        while(str[i] != ']')
                        {
                            fprintf(oneFile, "%c", str[i]);
                            ++i;
                        }
                        fprintf(oneFile, "]");
                    }
                    else
                    {
                        if(str[i] == 'u')
                        {
                            while(str[i] != ']')
                                ++i;
                        }
                        else
                        {
                            while(str[i] != ' ')
                                ++i;
                            ++i;
                            while(str[i] != ']')
                            {
                                fprintf(oneFile, "%c", str[i]);
                                ++i;
                            }
                            fprintf(oneFile, "]");
                        }
                    }
                }
            }

        }
    }

    fclose(inFile);
    fclose(oneFile);
}

void stepTwo()
{
    FILE *oneFile, *outFile;
    int i, j, len, left = 0, right = 0;
    char str[N];

    oneFile = fopen("stepOne.txt", "r");
    outFile = fopen("output.txt", "w");

    if(!oneFile)
        printf("No File Available.\n");

    else
    {
        while(fgets(str, N-1, oneFile))
        {
            for(i = 0; i < N-1; ++i)
            {

                if(str[i] == '[')
                {
                    fprintf(outFile, "[");
                    ++i;
                    if(str[i] == 'i' && str[i+1] == 'd')
                    {
                        fprintf(outFile, "id ");
                        i += 2;
                        j = 0;
                        while(str[i] != ']')
                        {
                            check[j] = str[i];
                            ++i;
                            ++j;
                        }
                        check[j] = '\0';

                        if(str[i+2] == '(')
                            iType = 1;
                        else
                            iType = 0;
                        tabSearch();
                        int x;
                        for(x = cnt; x >= 0; --x)
                            if(strcmp(tabVal[x].name, check) == 0)
                                break;
                        fprintf(outFile, "%d]", x+1);
                        if(str[i+2] == ';' || str[i+2] == ')' || str[i+2] == '}')
                            --topD;
                        if(str[i+2] == '=')
                        {
                            fprintf(outFile, "[=][");
                            i += 5;
                            j = 0;
                            int k, l, m;
                            for(m = cnt; m >= 0; --m)
                                if(strcmp(tabVal[m].name, check) == 0)
                                    break;
                            while(str[i] != ']')
                            {
                                check[j] = str[i];
                                ++i;
                                ++j;
                            }
                            check[j] = '\0';
                            l = strlen(check);

                            for(k = 0; k < l; ++k)
                                if(!isdigit(check[k]))
                                    break;
                            if(k == l)
                            {
                                fprintf(outFile, "%s]", check);
                                strcpy(tabVal[m].val, check);
                            }
                            else if(check[k] == '.')
                            {
                                ++k;
                                for(; k < l; ++k)
                                    if(!isdigit(check[k]))
                                        break;
                                if(k == l)
                                {
                                    fprintf(outFile, "%s]", check);
                                    strcpy(tabVal[m].val, check);
                                }
                            }
                            else if(k == 0)
                            {
                                cur[0] = ' ';
                                for(m = 3; m < l; ++m)
                                    cur[m-2] = check[m];
                                cur[m] = '\0';
                                for(m = cnt-1; m >= 0; --m)
                                {
                                    if(strcmp(tabVal[m].name, cur) == 0 && strcmp(tabVal[m].iT, "func") == 0 && str[i+2] == '(')
                                    {
                                        fprintf(outFile, "id %d]", tabVal[m].id);
                                        break;
                                    }
                                    else if(strcmp(tabVal[m].name, cur) == 0 && strcmp(tabVal[m].iT, "var") == 0 && str[i+2] != '(')
                                    {
                                        fprintf(outFile, "id %d]", tabVal[m].id);
                                        break;
                                    }
                                }
                            }

                        }
                    }
                    else
                    {
                        j = 0;
                        while(str[i] != ']')
                        {
                            check[j] = str[i];
                            ++i;
                            ++j;
                        }
                        check[j] = '\0';
                        fprintf(outFile, "%s]", check);

                        if(strcmp(check, "int") == 0 || strcmp(check, "float") == 0 || strcmp(check, "double") == 0 || strcmp(check, "char") == 0)
                        {
                            ++topD;
                            strcpy(dType[topD], check);
                        }
                        if(strcmp(check, "}") == 0)
                            --topS;
                    }
                }
            }
        }
    }
    fclose(oneFile);
    fclose(outFile);
}

void tabInsert()
{
    tabVal[cnt].id = cnt + 1;
    strcpy(tabVal[cnt].name, cur);
    strcpy(tabVal[cnt].dT, dType[topD]);
    if(topS == -1)
        strcpy(tabVal[cnt].sc, "global");
    else
        strcpy(tabVal[cnt].sc, scope[topS]);

    if(iType == 1)
    {
        strcpy(tabVal[cnt].iT, "func");
        scopeVal();
    }
    else
        strcpy(tabVal[cnt].iT, "var");
    strcpy(tabVal[cnt].val, "NULL");

    ++cnt;
}

void tabSearch()
{
    int i;

    strcpy(cur, check);

    for(i = 0; i < cnt; ++i)
    {
        if(strcmp(check, tabVal[i].name) == 0 && strcmp(tabVal[i].sc, scope[topS]) == 0)
            break;
        else if(strcmp(check, tabVal[i].name) == 0 && iType == 1 && strcmp(tabVal[i].iT, "func") == 0)
            break;
    }
    if(i == cnt)
        tabInsert();
}

void scopeVal()
{
    int i;

    for(i = cnt; i >= 0; --i)
        if(strcmp(tabVal[i].iT, "func") == 0)
            break;

    if(i >= 0)
    {
        ++topS;
        strcpy(scope[topS], tabVal[i].name);
    }
}
