#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(const vector<string> &prods)
{
    if (prods.empty())
        return "";
    string prefix = prods[0];
    for (int i = 1; i < prods.size(); i++)
    {
        int j = 0;
        while (j < prefix.size() && j < prods[i].size() && prefix[j] == prods[i][j])
        {
            j++;
        }
        prefix = prefix.substr(0, j);
        if (prefix.empty())
            break;
    }
    return prefix;
}

vector<vector<string>> eliminateLF(vector<vector<string>> grammar)
{
    vector<vector<string>> newGrammar;
    static int newCnt = 1;

    for (auto &row : grammar)
    {
        string nonTerminal = row[0];
        vector<string> prods(row.begin() + 1, row.end());
        sort(prods.begin(), prods.end());

        vector<string> newRow;
        newRow.push_back(nonTerminal);

        vector<bool> used(prods.size(), false);

        for (int i = 0; i < prods.size(); i++)
        {
            if (used[i])
                continue;
            vector<string> group{prods[i]};
            used[i] = true;

            for (int j = i + 1; j < prods.size(); j++)
            {
                if (!used[j])
                {
                    string prefix = longestCommonPrefix({prods[i], prods[j]});
                    if (!prefix.empty())
                    {
                        group.push_back(prods[j]);
                        used[j] = true;
                    }
                }
            }

            if (group.size() == 1)
            {
                newRow.push_back(group[0]);
            }
            else
            {
                string cmnPrefix = longestCommonPrefix(group);
                string newNT = nonTerminal + to_string(newCnt++);
                newRow.push_back(cmnPrefix + newNT);

                vector<string> newNTRow{newNT};
                for (auto &prod : group)
                {
                    string rem = prod.substr(cmnPrefix.size());
                    if (rem.empty())
                        rem = "ε";
                    newNTRow.push_back(rem);
                }

                vector<vector<string>> rec = eliminateLF({newNTRow});
                for (auto &r : rec)
                    newGrammar.push_back(r);
            }
        }

        newGrammar.push_back(newRow);
    }

    return newGrammar;
}

void Display(vector<vector<string>> grammar, string title = "Grammar")
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

        cout << "Enter productions for " << V << " (Type end to stop) " << V << " -> ";
        string p;
        while (cin >> p)
        {
            if (p == "end")
                break;
            row.push_back(p);
        }
        grammar.push_back(row);
    }

    Display(grammar, "Original Grammar");

    vector<vector<string>> factGm = eliminateLF(grammar);

    cout << "\nGrammar after eliminating left factoring:\n";
    cout << "-------------------\n";

    if (!factGm.empty())
    {
        auto &lastRow = factGm.back();
        cout << lastRow[0] << " -> ";
        for (int j = 1; j < lastRow.size(); j++)
        {
            cout << lastRow[j];
            if (j != lastRow.size() - 1)
                cout << " | ";
        }
        cout << endl;
    }

    for (int i = 0; i < (int)factGm.size() - 1; i++)
    {
        auto &row = factGm[i];
        cout << row[0] << " -> ";
        for (int j = 1; j < row.size(); j++)
        {
            cout << row[j];
            if (j != row.size() - 1)
                cout << " | ";
        }
        cout << endl;
    }
    return 0;
}