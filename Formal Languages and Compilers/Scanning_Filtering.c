#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *codeFile, *extractFile, *filterFile;
    char str[200];
    int i, j, l, stat = 0;

    codeFile = fopen("input.c", "r");
    extractFile = fopen("output.txt", "w");

    if(!codeFile)
        printf("No File Available.\n");

    else
    {
        printf("Source File:\n");
        while(fgets(str, 199, codeFile))
        {
            l = strlen(str);
            i = 0;

            while(i < l)
            {
                if(str[i] != ' ')
                    break;
                printf("%c", str[i]);
                ++i;
            }

            for(; i < l; ++i)
            {
                printf("%c", str[i]);
                if(stat == 0 && str[i] == '/')
                {
                    if(i < l-1 && str[i + 1] == '/')
                    {
                        for(j = i + 1; j < l; ++j)
                            printf("%c", str[j]);
                        break;
                    }
                    else if(i < l-1 && str[i + 1] == '*')
                    {
                        printf("*");
                        stat = 1;
                        ++i;
                        continue;
                    }
                }

                if(stat == 1)
                {
                    if(str[i] == '*' && str[i + 1] == '/')
                    {
                        printf("/");
                        stat = 0;
                        ++i;
                        continue;
                    }
                }
                else
                {
                    if(str[i] == ' ')
                    {
                        for(j = i + 1; j < l; ++j)
                        {
                            printf("%c", str[j]);
                            if(str[j] != ' ')
                                break;
                        }
                        if(str[j] == '/')
                        {
                            if(str[j + 1] == '/')
                            {
                                ++j;
                                while(j < l)
                                {
                                    printf("%c", str[j]);
                                    ++j;
                                }
                                break;
                            }
                            else if(str[j + 1] == '*')
                            {
                                printf("/*");
                                stat = 1;
                                ++i;
                                continue;
                            }
                        }

                        i = j;
                        fputc(' ', extractFile);
                        fputc(str[i], extractFile);
                        continue;
                    }
                    if(str[i] != '\n')
                        fputc(str[i], extractFile);
                }
            }
            printf("\n");
        }
    }

    fclose(codeFile);
    fclose(extractFile);

    filterFile = fopen("output.txt", "r");

    printf("\n\nFilter File:\n");

    if(!filterFile)
        printf("File not found");
    else
        while(fgets(str, 99, filterFile))
            printf("%s", str);
    fclose(filterFile);

    return 0;
}
