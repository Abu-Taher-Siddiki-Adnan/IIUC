#include <bits/stdc++.h>
using namespace std;

map<int, map<char, set<int>>> nfa;
const int START = 0;
const int FINAL = 11;
const char EPS = 'E';

set<int> epsilonClosure(const set<int> &states)
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
    set<int> current = epsilonClosure({START});
    for (char ch : s)
    {
        if (ch != 'a' && ch != 'b')
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
        current = epsilonClosure(moved);
        if (current.empty())
            return false;
    }
    current = epsilonClosure(current);
    return current.count(FINAL) > 0;
}

void buildNFA()
{
    // Union: START --eps--> 1 and START --eps--> 5
    nfa[START][EPS].insert(0);

    // a* fragment
    nfa[1][EPS].insert(2);
    nfa[1][EPS].insert(4);
    nfa[2]['a'].insert(3);
    nfa[3][EPS].insert(2);
    nfa[3][EPS].insert(4);

    // b(a|b) fragment
    nfa[5]['b'].insert(6);
    nfa[6]['a'].insert(7);
    nfa[6]['b'].insert(7);

    // connect fragment finals to overall FINAL via epsilons
    nfa[4][EPS].insert(FINAL);
    nfa[7][EPS].insert(FINAL);
}

void printNFA()
{
    cout << "NFA transitions:\n";
    set<int> states;
    for (auto &p : nfa)
        states.insert(p.first);
    for (int st : states)
    {
        for (auto &sym_map : nfa[st])
        {
            char sym = sym_map.first;
            set<int> &des = sym_map.second;
            if (des.empty())
                continue;
            cout << "  q" << st << " -" << sym << "-> ";
            bool first = true;
            for (int d : des)
            {
                if (!first)
                    cout << ",";
                cout << "q" << d;
                first = false;
            }
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
            if (c != 'a' && c != 'b')
            {
                valid = false;
                break;
            }
        if (!valid)
        {
            cout << s << ": Invalid Input" << endl;
            continue;
        }
        cout << s << ": " << (isAccepted(s) ? "Accepted" : "Rejected") << endl;
    }
    return 0;
}
