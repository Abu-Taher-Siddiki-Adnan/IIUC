#include <stdio.h>
#include <stdlib.h>

int char_check(char ch)
{
    return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '"';
}

int main()
{
    FILE *inp, *out;
    char inputArray[1024], outputArray[1024];
    int idx = 0;

    inp = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    if (inp == NULL)
    {
        printf("Error: Cannot open input file\n");
        return 1;
    }
    if (out == NULL)
    {
        printf("Error: Cannot open output file\n");
        fclose(inp);
        return 1;
    }

    while (fgets(inputArray, sizeof(inputArray), inp) != NULL)
    {
        int flag = 0;
        int newline = 0;
        for (int i = 0; inputArray[i] != '\0'; i++)
        {
            if (char_check(inputArray[i]))
            {
                printf("%c", inputArray[i]);
                outputArray[idx++] = inputArray[i];
                flag = 1;
            }
            else
            {
                if (flag)
                {
                    flag = 0;
                    printf("\n");
                    outputArray[idx++] = '\n';
                    newline = 1;
                    if (inputArray[i] == '\n' || inputArray[i] == ' ')
                    {
                        continue;
                    }
                }
                if (inputArray[i] == '(')
                {
                    if (newline == 0)
                    {
                        printf("\n");
                        outputArray[idx++] = '\n';
                        newline = 1;
                    }
                    printf("%c", inputArray[i]);
                    outputArray[idx++] = inputArray[i];
                    i++;
                    while (inputArray[i] != ')')
                    {
                        printf("%c", inputArray[i]);
                        outputArray[idx++] = inputArray[i];
                        i++;
                    }
                    printf(")\n");
                    outputArray[idx++] = ')';
                    outputArray[idx++] = '\n';
                    newline = 1;
                    continue;
                }
                if (inputArray[i] == ' ' || inputArray[i] == '\n')
                {
                    if (flag == -1 || flag == 0)
                    {
                        continue;
                    }
                    printf("\n");
                    outputArray[idx++] = '\n';
                    flag = -1;
                }
                else
                {
                    printf("%c\n", inputArray[i]);
                    outputArray[idx++] = inputArray[i];
                    outputArray[idx++] = '\n';
                }
            }
        }
    }
    for (int i = 0; outputArray[i] != '\0'; i++)
    {
        printf("%c", outputArray[i]);
        fputc(outputArray[i], out);
    }
    fclose(inp);
    fclose(out);
    return 0;
}