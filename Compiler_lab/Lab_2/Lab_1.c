#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_identifier_start(char ch)
{
    return isalpha(ch) || ch == '_';
}

int is_identifier_char(char ch)
{
    return isalnum(ch) || ch == '_';
}

int is_num(char ch)
{
    return isdigit(ch);
}

char *keywords[] = {"int", "main"};
int is_keyword(char *token)
{
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++)
    {
        if (strcmp(keywords[i], token) == 0)
            return 1;
    }
    return 0;
}

int main()
{
    FILE *inFile, *outFile;
    inFile = fopen("input.txt", "r");
    outFile = fopen("output.txt", "w");

    if (inFile == NULL || outFile == NULL)
    {
        printf("Error: Can't open files\n");
        if (inFile != NULL) fclose(inFile);
        if (outFile != NULL) fclose(outFile);
        return 1;
    }

    char inputArray[1024];
    while (fgets(inputArray, sizeof(inputArray), inFile) != NULL)
    {
        int i = 0;
        while (inputArray[i] != '\0' && inputArray[i] != '\n')
        {
            if (is_identifier_start(inputArray[i]))
            {
                char token[128];
                int idx = 0;
                while (is_identifier_char(inputArray[i]) && idx < 127)
                {
                    token[idx++] = inputArray[i++];
                }
                token[idx] = '\0';
                if (!is_keyword(token))
                {
                    printf("Identifier: %s\n", token);
                    fprintf(outFile, "Identifier: %s\n", token);
                }
            }
            else if (is_num(inputArray[i]))
            {
                char token[128];
                int idx = 0;
                while(is_num(inputArray[i]))
                {
                    token[idx++]= inputArray[i++];
                }
                token[idx++] = '\0';
                printf("Number: %s\n",token);
                fprintf(outFile, "Number: %s\n",token);
            }
            else
            {
                i++;
            }
        }
    }

    fclose(inFile);
    fclose(outFile);
    return 0;
}