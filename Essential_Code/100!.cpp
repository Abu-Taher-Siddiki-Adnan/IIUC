//Write a program to find the 100!.
#include<bits/stdc++.h>
using namespace std;

string bigMult(string num,int x)
{
    string ans;
    int carry = 0;
    for(int i=num.size()-1;i>=0;i--)
    {
        int d = num[i] - '0';
        int m = x * d + carry;
        ans+= (m%10) + '0';
        carry= m/10;
    }
    while(carry)
    {
        ans+= carry%10 + '0';
        carry/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    string ans="1";
    for(int i=1;i<=100;i++)
        ans = bigMult(ans,i);
    cout << ans << endl;

    return 0;
}
