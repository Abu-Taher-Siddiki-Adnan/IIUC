#include <bits/stdc++.h>
using namespace std;

map<char, map<int, set<char>>> nfa;
char nfaFinalstate = 'C';

string stToStr(set<char> st)
{
    string res = "";
    for (char c : st)
        res += c;
    return res;
}

map<string, map<int, string>> DFA_build()
{
    map<string, map<int, string>> dfaTable;
    queue<set<char>> q;
    map<string, bool> visited;

    set<char> startState = {'A'};
    q.push(startState);
    visited[stToStr(startState)] = true;

    while (!q.empty())
    {
        set<char> curSet = q.front();
        q.pop();

        string curState = stToStr(curSet);

        for (int i = 0; i <= 1; i++)
        {
            set<char> nextSet;

            for (char c : curSet)
            {
                for (char nxt : nfa[c][i])
                    nextSet.insert(nxt);
            }
            string nextState = stToStr(nextSet);
            dfaTable[curState][i] = nextState;
            if (!visited[nextState])
            {
                visited[nextState] = true;
                q.push(nextSet);
            }
        }
    }
    return dfaTable;
}

bool isAccepted(string s, map<string, map<int, string>> dfa)
{
    string curState = "A";
    for (char c : s)
    {
        int inp = c - '0';
        curState = dfa[curState][inp];
    }

    for (char c : curState)
    {
        if (c == nfaFinalstate)
            return true;
    }
    return false;
}

int main()
{
    nfa['A'][0] = {'A', 'B'};
    nfa['A'][1] = {'A'};
    nfa['B'][0] = {'C'};
    nfa['B'][1] = {'B'};
    nfa['C'][0] = {'C'};
    nfa['C'][1] = {'C'};

    map<string, map<int, string>> dfa = DFA_build();
    cout << "DFA Transition Table: " << endl;
    for (auto entry : dfa)
    {
        string curState = entry.first;
        if (curState == "")
            continue;
        auto trnx = entry.second;
        for (auto p : trnx)
        {
            int inp = p.first;
            string nextState = p.second;
            if (nextState == "")
                continue;
            cout << "[" << curState << "] --" << inp << "--> [" << nextState << "]" << endl;
        }
    }

    cout << endl;

    string s;
    while (cin >> s)
    {
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