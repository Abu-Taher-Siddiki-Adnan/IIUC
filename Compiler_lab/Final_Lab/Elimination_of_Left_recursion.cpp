#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> eliminateLC(vector<vector<string>> grammar)
{
    vector<vector<string>> newGrammar;

    for (auto &row : grammar)
    {
        string nonTerminal = row[0];
        vector<string> alpha; 
        vector<string> beta; 

        for (int j = 1; j < row.size(); j++)
        {
            string prod = row[j];

            if (prod.find(nonTerminal) == 0)
            {
                string rem = prod.substr(nonTerminal.length());
                if (rem.empty())
                    alpha.push_back("Ep");
                else
                    alpha.push_back(rem);
            }
            else
                beta.push_back(prod);
        }

        if (!alpha.empty())
        {
            string newNT = nonTerminal + "'";

            vector<string> newRow;
            newRow.push_back(nonTerminal);

            if (beta.empty())
                newRow.push_back(newNT);
            else
            {
                for (auto &b : beta)
                    newRow.push_back(b + newNT);
            }
            newGrammar.push_back(newRow);

            vector<string> newNTRow;
            newNTRow.push_back(newNT);

            for (auto &a : alpha)
            {
                if (a == "Ep")
                    newNTRow.push_back(newNT);
                else
                    newNTRow.push_back(a + newNT);
            }
            newNTRow.push_back("Ep");
            newGrammar.push_back(newNTRow);
        }
        else
            newGrammar.push_back(row);
    }

    return newGrammar;
}

void displayGrammar(vector<vector<string>> grammar, string title = "Grammar")
{
    cout << "\n" << title << ":\n";
    cout << "-------------------\n";
    for (auto &row : grammar)
    {
        cout << row[0] << " -> ";
        for (int j = 1; j < row.size(); j++)
        {
            cout << row[j];
            if (j != row.size() - 1)
                cout << " | ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<string>> grammar;
    int n;

    cout << "Enter number of non-terminals: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter a Non-Terminal: ";
        string V;
        cin >> V;

        vector<string> row;
        row.push_back(V);

        cout << "Enter productions for " << V << " (Type end to stop)..\n " << V << " -> ";
        string p;
        while (cin >> p)
        {
            if (p == "end")
                break;
            row.push_back(p);
        }
        grammar.push_back(row);
    }

    displayGrammar(grammar, "Original Grammar");

    vector<vector<string>> transformedGrammar = eliminateLC(grammar);

    displayGrammar(transformedGrammar, "Grammar after eliminating left recursion");

    return 0;
}