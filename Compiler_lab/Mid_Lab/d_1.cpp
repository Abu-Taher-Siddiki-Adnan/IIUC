#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char input[100] = "int x = y + 45;";
    char keywords[4][10] = {"int", "float", "if", "else"};

    int i = 0;
    cout << "Input: " << input << endl
         << endl;

    while (input[i] != '\0')
    {

        if (input[i] == ' ')
        {
            i++;
            continue;
        }

        if (isalpha(input[i]))
        {
            char buffer[20];
            int j = 0;

            while (isalnum(input[i]))
            {
                buffer[j++] = input[i++];
            }
            buffer[j] = '\0';

            bool isKeyword = false;
            for (int k = 0; k < 4; k++)
            {
                if (strcmp(buffer, keywords[k]) == 0)
                {
                    isKeyword = true;
                    break;
                }
            }

            if (isKeyword)
                cout << buffer << "  --> KEYWORD" << endl;
            else
                cout << buffer << "  --> IDENTIFIER" << endl;

            continue;
        }

        if (isdigit(input[i]))
        {
            char buffer[20];
            int j = 0;

            while (isdigit(input[i]))
            {
                buffer[j++] = input[i++];
            }
            buffer[j] = '\0';

            cout << buffer << "  --> NUMBER" << endl;
            continue;
        }

        if (input[i] == '+' || input[i] == '-' || input[i] == '*' ||
            input[i] == '/' || input[i] == '=')
        {
            cout << input[i] << "  --> OPERATOR" << endl;
            i++;
            continue;
        }

        i++;
    }

    return 0;
}
