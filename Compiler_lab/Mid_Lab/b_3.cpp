#include <bits/stdc++.h>
using namespace std;

map<char, map<char, set<char>>> nfa;
char nfaFinalState = '2';

string setToStr(set<char> st)
{
    string res = "";
    for (char c : st)
        res += c;

    return res;
}

set<char> epClosure(set<char> currentSet)
{
    stack<char> s;
    set<char> closure = currentSet;

    for (char state : currentSet)
        s.push(state);

    while (!s.empty())
    {
        char state = s.top();
        s.pop();

        if (nfa.count(state) && nfa[state].count('E'))
        {
            for (char nextState : nfa[state]['E'])
            {
                if (closure.find(nextState) == closure.end())
                {
                    closure.insert(nextState);
                    s.push(nextState);
                }
            }
        }
    }
    return closure;
}

map<string, map<char, string>> buildDFA()
{
    map<string, map<char, string>> dfaTable;
    queue<set<char>> q;
    map<string, bool> visited;

    set<char> startSet = epClosure({'0'});
    q.push(startSet);
    visited[setToStr(startSet)] = true;

    while (!q.empty())
    {
        set<char> curSet = q.front();
        q.pop();
        string curState = setToStr(curSet);

        for (char inp : {'a', 'b'})
        {
            set<char> intSet;

            for (char c : curSet)
            {
                if (nfa.count(c) && nfa[c].count(inp))
                {
                    for (char nxt : nfa[c][inp])
                        intSet.insert(nxt);
                }
            }

            set<char> nextSet = epClosure(intSet);

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
    string curState = setToStr(epClosure({'0'}));

    for (char c : s)
    {
        if (dfa.count(curState) == 0 || dfa[curState].count(c) == 0)
        {
            return false;
        }
        curState = dfa[curState][c];
        if (curState.empty())
        {
            return false;
        }
    }

    for (char c : curState)
    {
        if (c == nfaFinalState)
            return true;
    }
    return false;
}

int main()
{
    nfa['0']['E'] = {'1'};
    nfa['1']['a'] = {'1'};
    nfa['1']['b'] = {'2'};
    nfa['0']['a'] = {};
    nfa['0']['b'] = {};
    nfa['2']['a'] = {};
    nfa['2']['b'] = {};

    map<string, map<char, string>> dfa = buildDFA();

    map<string, string> stateNameMap = {{"01", "A"}, {"1", "B"}, {"2", "C"}, {"", "Dead"}};

    cout << "DFA Transition Table: " << endl;
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