#include <bits/stdc++.h>
using namespace std;

int precedence(char op)
{
    if (op == '+' or op == '-')
        return 1;
    if (op == '*' or op == '/')
        return 2;
    return 0;
}
string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix = "";
    for(int i=0; i<infix.length();i++)
    {
        char c = infix[i];
        if(isalnum(c))
            postfix += c;
        else if(c == '(')
            st.push(c);
        else if(c == ')')
        {
            while(st.top()!='(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && precedence(c) <= precedence(st.top()))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}
int main()
{
    string infix = "A+B*C-D/E";
    cin >> infix;
    cout << "Postfix Notation: " << infixToPostfix(infix) << endl;
    return 0;
}
