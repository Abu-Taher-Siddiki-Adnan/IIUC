#include <bits/stdc++.h>
using namespace std;

bool isValidInteger(const string &s)
{
    if (s.empty())
        return false;

    size_t i = 0;
    // optional sign
    if (s[0] == '+' || s[0] == '-')
    {
        if (s.size() == 1)
            return false; // only a sign is not a number
        i = 1;
    }

    // must have at least one digit
    bool hasDigit = false;
    for (; i < s.size(); ++i)
    {
        if (!isdigit(static_cast<unsigned char>(s[i])))
            return false;
        hasDigit = true;
    }
    return hasDigit;
}

int main()
{
    string s;
    while (cin >> s)
    {
        if (isValidInteger(s))
            cout << "'" << s << "' is a valid integer." << endl;
        else
            cout << "'" << s << "' is Constant." << endl;
    }

    return 0;
}