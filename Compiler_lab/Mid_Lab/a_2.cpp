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
            int one = 0;
            for (char c : s)
            {
                if (c == '1')
                    one++;
            }
            if (one % 2 == 0)
                cout << "Accepted" << endl;
            else
                cout << "Rejected" << endl;
        }
    }

    return 0;
}