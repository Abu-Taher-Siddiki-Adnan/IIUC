#include <bits/stdc++.h>
using namespace std;

map<char, vector<string>> grammar;
map<char, set<char>> first, follow;
vector<char> nonTerminals;

bool isTerminal(char ch)
{
    return !isupper(ch) || ch == '#' || ch == 'ε';
}

void computeFirst(char nonTerm)
{
    if (!first[nonTerm].empty())
        return;

    for (string prod : grammar[nonTerm])
    {
        for (int i = 0; i < prod.length(); i++)
        {
            char symbol = prod[i];

            if (isTerminal(symbol))
            {
                first[nonTerm].insert(symbol);
                break;
            }
            else
            {
                computeFirst(symbol);
                for (char ch : first[symbol])
                {
                    if (ch != 'ε')
                    {
                        first[nonTerm].insert(ch);
                    }
                }

                if (first[symbol].find('ε') == first[symbol].end())
                {
                    break;
                }

                if (i == prod.length() - 1)
                {
                    first[nonTerm].insert('ε');
                }
            }
        }
    }
}

void computeFollow(char nonTerm)
{
    if (nonTerm == nonTerminals[0])
    {
        follow[nonTerm].insert('$');
    }

    for (auto &rule : grammar)
    {
        char lhs = rule.first;
        for (string prod : rule.second)
        {
            for (int i = 0; i < prod.length(); i++)
            {
                if (prod[i] == nonTerm)
                {
                    if (i + 1 < prod.length())
                    {
                        char next = prod[i + 1];
                        if (isTerminal(next))
                        {
                            follow[nonTerm].insert(next);
                        }
                        else
                        {
                            for (char ch : first[next])
                            {
                                if (ch != 'ε')
                                {
                                    follow[nonTerm].insert(ch);
                                }
                            }

                            if (first[next].find('ε') != first[next].end())
                            {
                                for (char ch : follow[lhs])
                                {
                                    follow[nonTerm].insert(ch);
                                }
                            }
                        }
                    }
                    else
                    {
                        for (char ch : follow[lhs])
                        {
                            follow[nonTerm].insert(ch);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    cout << "======= First and Follow Sets =======" << endl;

    int n;
    cout << "Enter number of productions: ";
    cin >> n;
    cin.ignore();

    cout << "Enter productions (format: S->aB|ε): " << endl;
    for (int i = 0; i < n; i++)
    {
        string prod;
        cout << "Production " << i + 1 << ": ";
        getline(cin, prod);

        char lhs = prod[0];
        if (i == 0)
            nonTerminals.push_back(lhs);

        string rhs = prod.substr(3);
        string current = "";
        vector<string> productions;

        for (char ch : rhs)
        {
            if (ch == '|')
            {
                if (!current.empty())
                    productions.push_back(current);
                current = "";
            }
            else if (ch != ' ')
            {
                current += ch;
            }
        }
        if (!current.empty())
            productions.push_back(current);

        grammar[lhs] = productions;

        if (find(nonTerminals.begin(), nonTerminals.end(), lhs) == nonTerminals.end())
        {
            nonTerminals.push_back(lhs);
        }
    }

    for (char nt : nonTerminals)
    {
        computeFirst(nt);
    }

    for (int i = 0; i < 3; i++)
    { 
        for (char nt : nonTerminals)
        {
            computeFollow(nt);
        }
    }

    cout << "\n======= First Sets =======" << endl;
    for (char nt : nonTerminals)
    {
        cout << "FIRST(" << nt << ") = { ";
        for (char ch : first[nt])
        {
            cout << ch << " ";
        }
        cout << "}" << endl;
    }

    cout << "\n======= Follow Sets =======" << endl;
    for (char nt : nonTerminals)
    {
        cout << "FOLLOW(" << nt << ") = { ";
        for (char ch : follow[nt])
        {
            cout << ch << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}