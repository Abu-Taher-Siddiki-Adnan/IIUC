#include <bits/stdc++.h>
using namespace std;

bool hasLC(vector<string> prodRow)
{
    string nonTerminal = prodRow[0];
    for (int i = 1; i < prodRow.size(); i++)
    {
        if (prodRow[i].find(nonTerminal) == 0)
            return true;
    }
    return false;
}

pair<vector<string>, vector<string>> sepProd(vector<string> prodRow)
{
    string nonTerminal = prodRow[0];
    vector<string> alpha, beta;
    for (int i = 1; i < prodRow.size(); i++)
    {
        string prod = prodRow[i];
        if (prod.find(nonTerminal) == 0)
        {
            string remaining = prod.substr(nonTerminal.length());
            alpha.push_back(remaining.empty() ? "Ep" : remaining);
        }
        else
            beta.push_back(prod);
    }
    return {alpha, beta};
}

vector<vector<string>> eliminateLC(vector<vector<string>> grammar)
{
    vector<vector<string>> newGrammar;
    for (auto &row : grammar)
    {
        if (!hasLC(row))
        {
            newGrammar.push_back(row);
            continue;
        }
        string nonTerminal = row[0];
        auto result = sepProd(row);
        auto alpha = result.first;
        auto beta = result.second;
        string newNT = nonTerminal + "'";
        vector<string> newRow = {nonTerminal};
        if (beta.empty())
            newRow.push_back(newNT);
        else
        {
            for (auto &b : beta)
                newRow.push_back(b + newNT);
        }
        newGrammar.push_back(newRow);
        vector<string> newNTRow = {newNT};
        for (auto &a : alpha)
            newNTRow.push_back(a + newNT);
        newNTRow.push_back("Ep");
        newGrammar.push_back(newNTRow);
    }
    return newGrammar;
}

bool isNonTerminal(string symbol, unordered_set<string> &nonTerminals)
{
    if (symbol.length() > 1 && symbol.back() == '\'')
    {
        string base = symbol.substr(0, symbol.length() - 1);
        return nonTerminals.find(base) != nonTerminals.end();
    }
    return nonTerminals.find(symbol) != nonTerminals.end();
}

bool isTerminal(string symbol, unordered_set<string> &nonTerminals)
{
    return !isNonTerminal(symbol, nonTerminals) && symbol != "Ep" && symbol != "" && symbol != "$";
}

unordered_map<string, unordered_set<string>> computeFirstSets(
    vector<vector<string>> &grammar,
    unordered_set<string> &nonTerminals)
{

    unordered_map<string, unordered_set<string>> first;

    for (auto &row : grammar)
    {
        first[row[0]] = unordered_set<string>();
    }

    bool changed;
    do
    {
        changed = false;

        for (auto &row : grammar)
        {
            string A = row[0]; 

            for (int i = 1; i < row.size(); i++)
            {
                string production = row[i];

                if (production == "Ep")
                {
                    if (first[A].find("Ep") == first[A].end())
                    {
                        first[A].insert("Ep");
                        changed = true;
                    }
                    continue;
                }

                bool allCanDeriveEpsilon = true;
                int pos = 0;

                while (pos < production.length() && allCanDeriveEpsilon)
                {
                    string symbol;

                    if (pos + 1 < production.length() && production[pos + 1] == '\'')
                    {
                        symbol = production.substr(pos, 2);
                        pos += 2;
                    }
                    else
                    {
                        symbol = production.substr(pos, 1);
                        pos += 1;
                    }

                    if (isTerminal(symbol, nonTerminals))
                    {
                        if (first[A].find(symbol) == first[A].end())
                        {
                            first[A].insert(symbol);
                            changed = true;
                        }
                        allCanDeriveEpsilon = false;
                        break;
                    }
                    else if (isNonTerminal(symbol, nonTerminals))
                    {
                        for (auto &f : first[symbol])
                        {
                            if (f != "Ep")
                            {
                                if (first[A].find(f) == first[A].end())
                                {
                                    first[A].insert(f);
                                    changed = true;
                                }
                            }
                        }

                        if (first[symbol].find("Ep") == first[symbol].end())
                        {
                            allCanDeriveEpsilon = false;
                        }
                    }
                }

                if (allCanDeriveEpsilon)
                {
                    if (first[A].find("Ep") == first[A].end())
                    {
                        first[A].insert("Ep");
                        changed = true;
                    }
                }
            }
        }
    } while (changed);

    return first;
}

void displayGrammar(vector<vector<string>> &grammar, string title = "Grammar")
{
    cout << "\n"
         << title << ":\n";
    cout << string(title.length() + 2, '-') << "\n";
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

void displayFirstSets(unordered_map<string, unordered_set<string>> &first)
{
    cout << "\nFIRST Sets:\n";
    cout << "------------\n";

    vector<string> sortedNTs;
    for (auto &entry : first)
        sortedNTs.push_back(entry.first);
    sort(sortedNTs.begin(), sortedNTs.end());

    for (auto &nt : sortedNTs)
    {
        cout << "FIRST(" << nt << ") = { ";
        vector<string> sortedSymbols(first[nt].begin(), first[nt].end());
        sort(sortedSymbols.begin(), sortedSymbols.end());

        bool firstElement = true;
        for (auto &symbol : sortedSymbols)
        {
            if (!firstElement)
                cout << ", ";
            cout << symbol;
            firstElement = false;
        }
        cout << " }\n";
    }
}

int main()
{
    vector<vector<string>> grammar;
    int n;

    cout << "=== FIRST Set Computation with Left Recursion Elimination ===\n";
    cout << "Enter number of non-terminals: ";
    cin >> n;

    unordered_set<string> nonTerminals;
    string startSymbol;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter a Non-Terminal: ";
        string V;
        cin >> V;
        nonTerminals.insert(V);

        if (i == 0)
            startSymbol = V;

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

    cout << "\n";
    displayGrammar(grammar, "Original Grammar");

    bool leftRecursionFound = false;
    for (auto &row : grammar)
    {
        if (hasLC(row))
        {
            leftRecursionFound = true;
            break;
        }
    }
    if (leftRecursionFound)
    {
        grammar = eliminateLC(grammar);

        nonTerminals.clear();
        for (auto &row : grammar)
            nonTerminals.insert(row[0]);

        displayGrammar(grammar, "Grammar after eliminating left recursion");
    }

    auto first = computeFirstSets(grammar, nonTerminals);
    displayFirstSets(first);

    return 0;
}