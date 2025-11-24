#include <bits/stdc++.h>
using namespace std;

map<int, map<char, set<int>>> nfa;
const int START = 0;
const int FINAL = 4;
const char EPS = 'E';

set<int> epsilonClosure(const set<int> &states)
{
	set<int> closure = states;
	stack<int> st;
	for (int v : states) st.push(v);
	while (!st.empty())
	{
		int cur = st.top(); st.pop();
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
		if (ch != 'a' && ch != 'b') return false;
		set<int> moved;
		for (int st : current)
		{
			if (nfa.count(st) && nfa[st].count(ch))
			{
				for (int nx : nfa[st][ch]) moved.insert(nx);
			}
		}
		current = epsilonClosure(moved);
		if (current.empty()) return false;
	}
	current = epsilonClosure(current);
	return current.count(FINAL) > 0;
}


void buildNFA()
{
	
	nfa[0][EPS].insert(1);

	nfa[1][EPS].insert(2);
	nfa[2]['a'].insert(3);
	nfa[3]['b'].insert(5);

	nfa[1]['b'].insert(5);

	nfa[5][EPS].insert(1);
	nfa[5][EPS].insert(6);

	nfa[6]['a'].insert(FINAL);

	nfa[1][EPS].insert(6);
}

void printNFA()
{
	cout << "NFA transitions:\n";
	set<int> states;
	for (auto &p : nfa) states.insert(p.first);
	for (int st : states)
	{
		for (auto &sym_map : nfa[st])
		{
			char sym = sym_map.first;
			set<int> &des = sym_map.second;
			if (des.empty()) continue;
			cout << "  q" << st << " -" << sym << "-> ";
			bool first = true;
			for (int d : des)
			{
				if (!first) cout << ",";
				cout << "q" << d;
				first = false;
			}
			cout << endl;
		}
	}
}

int main()
{
	buildNFA();
	printNFA();

	string s;
	while (cin >> s)
	{
		bool valid = true;
		for (char c : s) if (c != 'a' && c != 'b') { valid = false; break; }
		if (!valid) { cout << s << ": Invalid Input" << endl; continue; }
		cout << s << ": " << (isAccepted(s) ? "Accepted" : "Rejected") << endl;
	}
	return 0;
}

