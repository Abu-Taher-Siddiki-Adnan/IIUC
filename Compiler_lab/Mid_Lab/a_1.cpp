#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        int n = s.size();
        bool flag = true;
        for (char c : s)
        {
            if (c != '0' and c != '1')
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            cout << "Invalid Input" << endl;
        else
        {
            if (n >= 2 and s[n - 2] == '0' and s[n - 1] == '1')
                cout << "Accepted" << endl;
            else
                cout << "Rejected" << endl;
        }
    }

    return 0;
}