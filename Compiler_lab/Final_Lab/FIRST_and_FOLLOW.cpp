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
            alpha.push_back(remaining.empty() ? "ε" : remaining);
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
        newNTRow.push_back("ε");
        newGrammar.push_back(newNTRow);
    }
    return newGrammar;
}

bool isNonTerminal(string symbol, unordered_set<string> &nonTerminals)
{
    if (symbol == "ε" || symbol == "$")
        return false;

    if (symbol.length() > 1 && symbol.back() == '\'')
    {
        string base = symbol.substr(0, symbol.length() - 1);
        return nonTerminals.find(base) != nonTerminals.end();
    }
    return nonTerminals.find(symbol) != nonTerminals.end();
}

bool isTerminal(string symbol)
{
    if (symbol.empty() || symbol == "ε" || symbol == "$")
        return false;

    if (symbol.length() == 1)
    {
        char c = symbol[0];
        return !isupper(c) && c != '\'';
    }

    for (char c : symbol)
    {
        if (c == '\'')
            return false;
    }

    return true;
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

                if (production == "ε")
                {
                    if (first[A].find("ε") == first[A].end())
                    {
                        first[A].insert("ε");
                        changed = true;
                    }
                    continue;
                }

                bool allCanDeriveEpsilon = true;
                int pos = 0;
                int len = production.length();

                while (pos < len && allCanDeriveEpsilon)
                {
                    if (isupper(production[pos]) && (pos + 1 >= len || production[pos + 1] != '\''))
                    {
                        string symbol = production.substr(pos, 1);

                        if (isTerminal(symbol))
                        {
                            if (first[A].find(symbol) == first[A].end())
                            {
                                first[A].insert(symbol);
                                changed = true;
                            }
                            allCanDeriveEpsilon = false;
                            break;
                        }
                        else
                        {
                            for (auto &f : first[symbol])
                            {
                                if (f != "ε")
                                {
                                    if (first[A].find(f) == first[A].end())
                                    {
                                        first[A].insert(f);
                                        changed = true;
                                    }
                                }
                            }

                            if (first[symbol].find("ε") == first[symbol].end())
                            {
                                allCanDeriveEpsilon = false;
                            }
                            pos += 1;
                        }
                    }
                    else if (pos + 1 < len && production[pos + 1] == '\'')
                    {
                        string symbol = production.substr(pos, 2);

                        for (auto &f : first[symbol])
                        {
                            if (f != "ε")
                            {
                                if (first[A].find(f) == first[A].end())
                                {
                                    first[A].insert(f);
                                    changed = true;
                                }
                            }
                        }

                        if (first[symbol].find("ε") == first[symbol].end())
                        {
                            allCanDeriveEpsilon = false;
                        }
                        pos += 2;
                    }
                    else
                    {

                        int start = pos;
                        while (pos < len && !isupper(production[pos]) &&
                               (pos + 1 >= len || production[pos + 1] != '\''))
                        {
                            pos++;
                        }
                        string symbol = production.substr(start, pos - start);

                        if (first[A].find(symbol) == first[A].end())
                        {
                            first[A].insert(symbol);
                            changed = true;
                        }
                        allCanDeriveEpsilon = false;
                        break;
                    }
                }

                if (allCanDeriveEpsilon)
                {
                    if (first[A].find("ε") == first[A].end())
                    {
                        first[A].insert("ε");
                        changed = true;
                    }
                }
            }
        }
    } while (changed);

    return first;
}

unordered_set<string> getFirstOfString(string str,
                                       unordered_map<string, unordered_set<string>> &first,
                                       unordered_set<string> &nonTerminals)
{
    unordered_set<string> result;

    if (str.empty() || str == "ε")
    {
        result.insert("ε");
        return result;
    }

    int i = 0;
    int len = str.length();
    bool canDeriveEpsilon = true;

    while (i < len && canDeriveEpsilon)
    {
        if (isupper(str[i]) && (i + 1 >= len || str[i + 1] != '\''))
        {
            string symbol = str.substr(i, 1);

            if (isTerminal(symbol))
            {
                result.insert(symbol);
                canDeriveEpsilon = false;
            }
            else
            {
                for (auto &f : first[symbol])
                {
                    if (f != "ε")
                        result.insert(f);
                }

                if (first[symbol].find("ε") == first[symbol].end())
                {
                    canDeriveEpsilon = false;
                }
                i += 1;
            }
        }
        else if (i + 1 < len && str[i + 1] == '\'')
        {
            string symbol = str.substr(i, 2);

            for (auto &f : first[symbol])
            {
                if (f != "ε")
                    result.insert(f);
            }

            if (first[symbol].find("ε") == first[symbol].end())
            {
                canDeriveEpsilon = false;
            }
            i += 2;
        }
        else
        {
            int start = i;
            while (i < len && !isupper(str[i]) &&
                   (i + 1 >= len || str[i + 1] != '\''))
            {
                i++;
            }
            string symbol = str.substr(start, i - start);
            result.insert(symbol);
            canDeriveEpsilon = false;
        }
    }

    if (canDeriveEpsilon)
    {
        result.insert("ε");
    }

    return result;
}

unordered_map<string, unordered_set<string>> computeFollowSets(
    vector<vector<string>> &grammar,
    unordered_map<string, unordered_set<string>> &first,
    unordered_set<string> &nonTerminals,
    string startSymbol)
{
    unordered_map<string, unordered_set<string>> follow;

    for (auto &row : grammar)
    {
        follow[row[0]] = unordered_set<string>();
    }

    follow[startSymbol].insert("$");

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
                int len = production.length();

                for (int pos = 0; pos < len;)
                {
                    string B;

                    if (pos + 1 < len && production[pos + 1] == '\'')
                    {
                        B = production.substr(pos, 2);
                        pos += 2;
                    }
                    else if (isupper(production[pos]))
                    {
                        B = production.substr(pos, 1);
                        pos += 1;
                    }
                    else
                    {
                        int start = pos;
                        while (pos < len && !isupper(production[pos]) &&
                               (pos + 1 >= len || production[pos + 1] != '\''))
                        {
                            pos++;
                        }
                        continue;
                    }

                    if (!isNonTerminal(B, nonTerminals))
                        continue;

                    string remaining = production.substr(pos);

                    if (!remaining.empty())
                    {
                        auto firstBeta = getFirstOfString(remaining, first, nonTerminals);

                        for (auto &f : firstBeta)
                        {
                            if (f != "ε")
                            {
                                if (follow[B].find(f) == follow[B].end())
                                {
                                    follow[B].insert(f);
                                    changed = true;
                                }
                            }
                        }

                        if (firstBeta.find("ε") != firstBeta.end())
                        {
                            for (auto &f : follow[A])
                            {
                                if (follow[B].find(f) == follow[B].end())
                                {
                                    follow[B].insert(f);
                                    changed = true;
                                }
                            }
                        }
                    }
                    else
                    {
                        for (auto &f : follow[A])
                        {
                            if (follow[B].find(f) == follow[B].end())
                            {
                                follow[B].insert(f);
                                changed = true;
                            }
                        }
                    }
                }
            }
        }
    } while (changed);

    return follow;
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
        vector<string> sortedSymbols;
        for (auto &symbol : first[nt])
        {
            if (symbol != "ε")
                sortedSymbols.push_back(symbol);
        }
        sort(sortedSymbols.begin(), sortedSymbols.end());

        if (first[nt].find("ε") != first[nt].end())
            sortedSymbols.push_back("ε");

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

void displayFollowSets(unordered_map<string, unordered_set<string>> &follow)
{
    cout << "\nFOLLOW Sets:\n";
    cout << "------------\n";

    vector<string> sortedNTs;
    for (auto &entry : follow)
        sortedNTs.push_back(entry.first);
    sort(sortedNTs.begin(), sortedNTs.end());

    for (auto &nt : sortedNTs)
    {
        cout << "FOLLOW(" << nt << ") = { ";
        vector<string> sortedSymbols;
        for (auto &symbol : follow[nt])
        {
            if (symbol != "ε")
                sortedSymbols.push_back(symbol);
        }
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

    cout << "=== FOLLOW Set Computation with Left Recursion Elimination ===\n";
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

    auto follow = computeFollowSets(grammar, first, nonTerminals, startSymbol);
    displayFollowSets(follow);

    return 0;
}