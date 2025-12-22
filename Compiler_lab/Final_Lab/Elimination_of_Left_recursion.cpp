#include <bits/stdc++.h>
using namespace std;

bool hasLC(vector<string> prodRow) {
    string nonTerminal = prodRow[0];
    
    for (int i = 1; i < prodRow.size(); i++) {
        if (prodRow[i].find(nonTerminal) == 0) {
            return true;
        }
    }
    return false;
}

pair<vector<string>, vector<string>> sepProd(vector<string> prodRow) {
    string nonTerminal = prodRow[0];
    vector<string> alpha, beta;
    
    for (int i = 1; i < prodRow.size(); i++) {
        string prod = prodRow[i];
        
        if (prod.find(nonTerminal) == 0) {
            string remaining = prod.substr(nonTerminal.length());
            alpha.push_back(remaining.empty() ? "ε" : remaining);
        } else {
            beta.push_back(prod);
        }
    }
    
    return {alpha, beta};
}

vector<vector<string>> eliminateLC(vector<vector<string>> grammar) {
    vector<vector<string>> newGrammar;
    
    for (auto &row : grammar) {
        if (!hasLC(row)) {
            newGrammar.push_back(row);
            continue;
        }
        
        string nonTerminal = row[0];
        auto [alpha, beta] = sepProd(row);
        
        string newNT = nonTerminal + "'";
        
        vector<string> newRow = {nonTerminal};
        if (beta.empty()) {
            newRow.push_back(newNT);
        } else {
            for (auto &b : beta) {
                newRow.push_back(b + newNT);
            }
        }
        newGrammar.push_back(newRow);
        
        vector<string> newNTRow = {newNT};
        for (auto &a : alpha) {
            newNTRow.push_back(a + newNT);
        }
        newNTRow.push_back("ε");
        newGrammar.push_back(newNTRow);
    }
    
    return newGrammar;
}

void Display(vector<vector<string>> grammar, string title = "Grammar") {
    cout << "\n" << title << ":\n";
    cout << "-------------------\n";
    for (auto &row : grammar) {
        cout << row[0] << " -> ";
        for (int j = 1; j < row.size(); j++) {
            cout << row[j];
            if (j != row.size() - 1) cout << " | ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<string>> grammar;
    int n;
    
    cout << "Enter number of non-terminals: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cout << "Enter a Non-Terminal: ";
        string V;
        cin >> V;

        vector<string> row;
        row.push_back(V);

        cout << "Enter productions for " << V << " (Type End to stop) " << V << " -> ";
        string p;
        while (cin >> p) {
            if (p == "End") break;
            row.push_back(p);
        }
        grammar.push_back(row);
    }

    Display(grammar, "Original Grammar");
    
    vector<vector<string>> transGmr = eliminateLC(grammar);
    
    Display(transGmr, "Grammar after eliminating left recursion");

    return 0;
}