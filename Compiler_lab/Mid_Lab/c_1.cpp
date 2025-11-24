#include <bits/stdc++.h>
using namespace std;

map<int, map<char, set<int>>> nfa;
const int START = 0;
const int FINAL = 1;
const char EPS = 'E';

set<int> epClosure(const set<int> &states)
{
    set<int> closure = states;
    stack<int> st;
    for (int v : states)
        st.push(v);
    while (!st.empty())
    {
        int cur = st.top();
        st.pop();
        if (nfa.count(cur) && nfa[cur].count(EPS))
        {
            for (int nxt : nfa[cur][EPS])
            {
                if (!closure.count(nxt))
                {
                    closure.insert(nxt);
                    st.push(nxt);
                }
            }
        }
    }
    return closure;
}

bool isAccepted(const string &s)
{
    set<int> current = epClosure({START});

    for (char ch : s)
    {
        if (ch != 'a' && ch != 'b' && ch != 'c')
            return false;
        set<int> moved;
        for (int st : current)
        {
            if (nfa.count(st) && nfa[st].count(ch))
            {
                for (int nx : nfa[st][ch])
                    moved.insert(nx);
            }
        }
        current = epClosure(moved);
        if (current.empty())
            return false;
    }

    current = epClosure(current);
    return current.count(FINAL) > 0;
}

void buildNFA()
{
    nfa[START]['a'].insert(1);
    nfa[1]['b'].insert(1);
    nfa[1]['c'].insert(1);
    nfa[1][EPS].insert(FINAL);
}

void printNFA()
{
    cout << "NFA transitions:" << endl;

    set<int> states;
    for (auto p : nfa)
        states.insert(p.first);

    for (int st : states)
    {
        for (auto sym_map : nfa[st])
        {
            char sym = sym_map.first;
            set<int> &des = sym_map.second;
            if (des.empty())
                continue;
            cout << "  q" << st << " -" << sym << "-> ";
            for (int d : des)
                cout << "q" << d;
            cout << endl;
        }
    }
    cout << endl;
}

int main()
{
    buildNFA();
    printNFA();

    string s;
    while (cin >> s)
    {
        bool valid = true;
        for (char c : s)
            if (c != 'a' && c != 'b' && c != 'c')
            {
                valid = false;
                break;
            }
        if (!valid)
        {
            cout << s << ":  Invalid Input" << endl;
            continue;
        }

        if (isAccepted(s))
            cout << s << ":  Accepted" << endl;
        else
            cout << s << ":  Rejected" << endl;
    }

    return 0;
}