#include <bits/stdc++.h>
using namespace std;

bool isValid(const string &s)
{
    if (s.empty())
        return false;
    if (!isalpha(s[0]) && s[0] != '_')
        return false;
    for (size_t i = 1; i < s.length(); ++i)
    {
        if (!isalnum(s[i]) && s[i] != '_')
            return false;
    }
    return true;
}

int main()
{
    string s;
    while (cin >> s)
    {
        if (isValid(s))
            cout << "'" << s << "' is a valid identifier." << endl;
        else
            cout << "'" << s << "' is an invalid identifier." << endl;
    }

    return 0;
}