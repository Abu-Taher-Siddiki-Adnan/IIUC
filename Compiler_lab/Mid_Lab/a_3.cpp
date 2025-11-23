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
            if (c != 'a' and c != 'b')
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            cout << "Invalid Input" << endl;
        else
        {
            bool rejected = false;
            for (int i = 0; i < n - 1; i++)
            {
                if (s[i] == 'b' && s[i + 1] == 'b')
                {
                    rejected = true;
                    break;
                }
            }
            if (rejected)
                cout << "Rejected" << endl;
            else
                cout << "Accepted" << endl;
        }
    }

    return 0;
}