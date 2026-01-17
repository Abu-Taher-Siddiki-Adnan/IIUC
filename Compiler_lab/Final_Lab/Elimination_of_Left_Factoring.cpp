#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "======= Elimination of Left Factoring =======" << endl;

    vector<string> newGrammar;
    int n;
    cout << "Enter number of Non-Terminals: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        char nT;
        cout << "Enter Non-terminal: ";
        cin >> nT;

        string prod;
        cout << "Enter productions (use | to separate): ";
        cin.ignore();
        getline(cin, prod);

        vector<string> prods;
        string current = "";

        for (char ch : prod)
        {
            if (ch == '|')
            {
                if (!current.empty())
                    prods.push_back(current);
                current = "";
            }
            else if (ch != ' ')
                current += ch;
        }
        if (!current.empty())
            prods.push_back(current);

        if (prods.size() < 2)
        {
            newGrammar.push_back(string(1, nT) + " -> " + prod);
            continue;
        }

        string common = prods[0];
        for (int j = 1; j < prods.size(); j++)
        {
            int k = 0;
            while (k < common.length() && k < prods[j].length() && common[k] == prods[j][k])
            {
                k++;
            }
            common = common.substr(0, k);
            if (common.empty())
                break;
        }

        if (common.empty())
            newGrammar.push_back(string(1, nT) + " -> " + prod);
        else
        {
            string newNT = string(1, nT) + "'";
            string newProd1 = string(1, nT) + " -> " + common + newNT;

            string newProd2 = newNT + " -> ";
            for (int j = 0; j < prods.size(); j++)
            {
                string rest = prods[j].substr(common.length());
                if (rest.empty())
                    rest = "ε";
                newProd2 += rest;
                if (j < prods.size() - 1)
                    newProd2 += " | ";
            }

            newGrammar.push_back(newProd1);
            newGrammar.push_back(newProd2);
        }
    }

    cout << "\n======= Grammar After Left Factoring =======" << endl;
    for (string &prod : newGrammar)
        cout << prod << endl;

    return 0;
}