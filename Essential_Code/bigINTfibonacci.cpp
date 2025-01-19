#include<bits/stdc++.h>
using namespace std;

string bigAdd(string a, string b)
{
    string ans;
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry)
    {
        int x = (i >= 0) ? (a[i] - '0') : 0;
        int y = (j >= 0) ? (b[j] - '0') : 0;
        int sum = x + y + carry;
        ans += (sum % 10) + '0';
        carry = sum / 10;
        i--, j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string fibonacci(int n)
{
    if (n == 1 || n == 2)
        return "1";
    string a = "1", b = "1", c;
    for (int i = 3; i <= n; i++)
    {
        c = bigAdd(a, b);
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int n = 500;
    string result = fibonacci(n);
    cout << "Fibonacci number " << n << " is: " << result << endl;
    return 0;
}

