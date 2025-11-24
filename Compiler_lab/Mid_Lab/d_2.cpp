#include<bits/stdc++.h>
using namespace std;

int main() {
    char code[] = "int x = a + b1; float y = x + 23; if(x > 0) x = x + 1;";
    
    char keywords[][10] = {"int", "float", "if", "else", "for", "while", "return", "double", "char"};
    int keywordCount = 9;

    int i = 0, identifierCount = 0;

    while (code[i] != '\0') {

        if (code[i] == ' ') {
            i++;
            continue;
        }

        if (isalpha(code[i]) || code[i] == '_') {

            char buffer[50];
            int j = 0;

            buffer[j++] = code[i++];
            while (isalnum(code[i]) || code[i] == '_') {
                buffer[j++] = code[i++];
            }
            buffer[j] = '\0';

            bool isKeyword = false;
            for (int k = 0; k < keywordCount; k++) {
                if (strcmp(buffer, keywords[k]) == 0) {
                    isKeyword = true;
                    break;
                }
            }

            if (!isKeyword) {
                identifierCount++;
            }

            continue;
        }

        i++;
    }

    cout << "\nTotal Identifiers Found: " << identifierCount << endl;

    return 0;
}
