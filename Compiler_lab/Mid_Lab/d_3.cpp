#include <bits/stdc++.h>
using namespace std;
string removeComments(const string &code)
{
    string ans = "";
    int i = 0;
    int n = code.size();
    while (i < n)
    {
        // single line comment
        if (i + 1 < n && code[i] == '/' && code[i + 1] == '/')
        {
            i += 2;
            while (i < n && code[i] != '\n')
                i++;
        }
        // multi line comment
        else if (i + 1 < n && code[i] == '/' && code[i + 1] == '*')
        {
            i += 2;
            while (i + 1 < n && code[i] != '*' && code[i + 1] != '/')
            {
                i++;
            }
            i += 2;
        }
        else
        {
            ans += code[i];
            i++;
        }
    }
    return ans;
}
int main()
{

    string code = R"(

#include <iostream> // include iostream
int main() {
    int x = 5; /* initialize x */
    int y = 10;
    // print sum
    cout << x + y;
    return 0;
}
)";

    cout << "Original Code:" << endl
         << code << endl;

    string cleaned = removeComments(code);

    cout << "\nCleaned Code (comments removed):" << endl
         << cleaned << endl;

    return 0;
}