#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define N 1000000

char* subString(char* str, int left, int right);
bool isKeyword(char* str);
bool isIdentifier(char* str, int len);
bool isSeparator(char ch);
bool isSingOprtr(char ch);
bool isMultOprtr(char* str);
bool isBinary(char* str, int len);
bool isDecimal(char* str, int len);
bool isOctal(char* str, int len);
bool isHexadecimal(char* str, int len);


int main(void)
{
    FILE *inFile, *outFile;
    int len, left = 0, right = 0;
    char str[N];
    int i, j, l, stat = 0;

    inFile = fopen("input.txt", "r");
    outFile = fopen("output.txt", "w");

    if(!inFile)
        printf("No File Available.\n");

    else
    {
        while(fgets(str, N-1, inFile))
        {
            len = strlen(str);

            while (right <= len && left <= right)
            {

                if(!isSeparator(str[right]) && !isSingOprtr(str[right]))
                    right++;
                if((isSeparator(str[right]) || isSingOprtr(str[right])) && left == right)
                {
                    if (isSeparator(str[right]) == true)
                        fprintf(outFile, "[sep %c] ", str[right]);
                    else
                    {
                        if(isSingOprtr(str[right + 1]))
                        {
                            ++right;
                            char* subStr = subString(str, left, right);
                            if(isMultOprtr(subStr))
                                fprintf(outFile, "[op %s] ", subStr);
                            else
                                fprintf(outFile, "[unkn %s] ", subStr);
                        }
                        else
                            fprintf(outFile, "[op %c] ", str[right]);
                    }
                    ++right;
                    left = right;
                }
                else if(isSeparator(str[right]) || isSingOprtr(str[right]) || (right == len && left != right))
                {
                    char* subStr = subString(str, left, right - 1);
                    if (isKeyword(subStr))
                        fprintf(outFile, "[kw %s] ", subStr);

                    else if (isBinary(subStr, right - left) || isOctal(subStr, right - left) ||
                             isHexadecimal(subStr, right - left) || isDecimal(subStr, right - left))
                        fprintf(outFile, "[number %s] ", subStr);

                    else if (isIdentifier(subStr, right - left) == true && isSeparator(str[right - 1]) == false)
                        fprintf(outFile, "[id %s] ", subStr);

                    else
                        fprintf(outFile, "[unkn %s] ", subStr);
                    left = right;
                }

            }
        }
    }

    fclose(inFile);
    fclose(outFile);

    return 0;
}

char* subString(char* str, int left, int right)
{
    int i;
    char* subStr = (char*)malloc(sizeof(char) * (right - left + 2));

    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}

bool isKeyword(char* str)
{
    if (!strcmp(str, "void") || !strcmp(str, "int") || !strcmp(str, "float") || !strcmp(str, "char") ||
        !strcmp(str, "for") || !strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") ||
        !strcmp(str, "return"))
        return true;
    return false;
}

bool isIdentifier(char* str, int len)
{
    int i;

    if(!isalpha(str[0]) &&  str[0] != '_')
        return false;
    for(i = 1; i < len; ++i)
        if(!isalnum(str[i]) && !(str[i] == '_'))
            return false;
    return true;
}

bool isSeparator(char ch)
{
    if (ch == ' ' || ch == ',' || ch == ';' || ch == '(' ||
            ch == ')' || ch == '[' || ch == ']' || ch == '{' ||  ch == '}')
        return true;
    return false;
}

bool isSingOprtr(char ch)
{
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%' ||
            ch == '=' || ch == '>' || ch == '!' || ch == '<')
        return true;
    return false;
}

bool isMultOprtr(char* str)
{
    if (!strcmp(str, "==") || !strcmp(str, "++") || !strcmp(str, "--") || !strcmp(str, "+=") ||
        !strcmp(str, "-=") || !strcmp(str, "*=") || !strcmp(str, "/=") || !strcmp(str, "%=") ||
        !strcmp(str, "<=") || !strcmp(str, ">=") || !strcmp(str, "!=") || !strcmp(str, "&&") ||
        !strcmp(str, "||"))
        return true;
    return false;
}

bool isBinary(char* str, int len)
{
    int i;

    if(len < 3 || str[0] != '0' || str[1] != 'b')
        return false;

    for(i = 2; i < len; ++i)
        if(str[i] < '0' || str[i] > '1')
            break;

    if(i == len)
        return true;

    if(str[i] != '.')
        return false;

    ++i;
    while(i < len)
    {
        if(str[i] < '0' || str[i] > '1')
            return false;
        ++i;
    }

    return true;
}

bool isDecimal(char* str, int len)
{
    int i;

    for(i = 0; i < len; ++i)
        if(!isdigit(str[i]))
            break;
    if(i == len)
        return true;

    if(str[i] != '.')
        return false;

    ++i;
    while(i < len)
    {
        if(!isdigit(str[i]))
            return false;
        ++i;
    }

    return true;
}

bool isOctal(char* str, int len)
{
    int i;

    if(len < 2 || str[0] != '0')
        return false;

    for(i = 1; i < len; ++i)
        if(str[i] < '0' || str[i] > '7')
            break;

    if(i == len)
        return true;

    if(str[i] != '.')
        return false;

    ++i;
    while(i < len)
    {
        if(str[i] < '0' || str[i] > '7')
            return false;
        ++i;
    }

    return true;
}

bool isHexadecimal(char* str, int len)
{
    int i;

    if(len < 3 || str[0] != '0' || (str[1] != 'x' && str[1] != 'X'))
        return false;

    for(i = 2; i < len; ++i)
        if(!isdigit(str[i]) && (str[i] < 'A' || str[i] > 'F'))
            break;

    if(i == len)
        return true;

    if(str[i] != '.')
        return false;

    ++i;
    while(i < len)
    {
        if(!isdigit(str[i]) && !(str[i] >= 'A' && str[i] <= 'F'))
            return false;
        ++i;
    }

    return true;
}
