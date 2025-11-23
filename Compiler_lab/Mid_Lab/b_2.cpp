#include <bits/stdc++.h>
using namespace std;

map<char, map<char, set<char>>> nfa;
char nfaFinalState = '3';

string setToStr(set<char> st)
{
    string res = "";
    for (char c : st)
        res += c;

    return res;
}

map<string, map<char, string>> buildDFA()
{
    map<string, map<char, string>> dfaTable;
    queue<set<char>> q;
    map<string, bool> visited;

    set<char> startState = {'0'};
    q.push(startState);
    visited[setToStr(startState)] = true;

    while (!q.empty())
    {
        set<char> curSet = q.front();
        q.pop();
        string curState = setToStr(curSet);

        for (char inp : {'a', 'b'})
        {
            set<char> nextSet;
            for (char c : curSet)
            {
                for (char nxt : nfa[c][inp])
                    nextSet.insert(nxt);
            }
            string nextState = setToStr(nextSet);
            dfaTable[curState][inp] = nextState;
            if (!visited[nextState])
            {
                visited[nextState] = true;
                q.push(nextSet);
            }
        }
    }
    return dfaTable;
}

bool isAccepted(string s, map<string, map<char, string>> dfa)
{
    string curState = "0";
    for (char c : s)
        curState = dfa[curState][c];
    for (char c : curState)
    {
        if (c == nfaFinalState)
            return true;
    }
    return false;
}

int main()
{
    nfa['0']['a'] = {'0', '1'};
    nfa['0']['b'] = {'0'};
    nfa['1']['a'] = {};
    nfa['1']['b'] = {'2'};
    nfa['2']['a'] = {};
    nfa['2']['b'] = {'3'};
    nfa['2']['a'] = {};
    nfa['3']['b'] = {};

    map<string, map<char, string>> dfa = buildDFA();

    cout << "DFA Transition Table:" << endl;
    for (auto entry : dfa)
    {
        string curState = entry.first;
        if (curState.empty())
            continue;
        for (auto trnx : entry.second)
        {
            char inp = trnx.first;
            string nextState = trnx.second;
            if (nextState.empty())
                continue;
            cout << "[" << curState << "] -- " << inp << " --> [" << nextState << "]" << endl;
        }
    }
    cout << endl;

    string s;
    while (cin >> s)
    {
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
            cout << s << ": Invalid Input" << endl;
        else
        {
            if (isAccepted(s, dfa))
                cout << s << ": Accepted" << endl;
            else
                cout << s << ": Rejected" << endl;
        }
    }
}