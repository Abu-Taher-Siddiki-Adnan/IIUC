#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "======= Elimination of Left Recursion =======" << endl;

    vector<string> newGrammar;
    int n;
    cout << "Enter the number of Non-Terminal: ";
    cin >> n;
    while (n--)
    {

        char nT;
        cout << "Enter the Non-terminal: ";
        cin >> nT;

        string prod;
        cout << "Enter the Production: ";
        cin.ignore();
        getline(cin, prod);

        string alpha = "", beta = "";
        
        if (prod[0] != nT)
            newGrammar.push_back(string(1, nT) + " -> " + prod);
        else
        {
            int i = 2;
            while (true)
            {
                if (prod[i] == '|')
                {
                    i++;
                    break;
                }
                alpha += prod[i];
                i++;
            }
            while (i <= prod.length() - 1)
            {
                beta += prod[i];
                i++;
            }

            string newProd1 = string(1, nT) + " -> " + beta + " " + string(1, nT) + "'";
            string newProd2 = string(1, nT) + "' -> " + alpha + " " + string(1, nT) + "' | ep";

            newGrammar.push_back(newProd1);
            newGrammar.push_back(newProd2);
            // //cout << alpha << " " << beta << endl;
            // cout << "Grammar after elimination of Left Recursion: " << endl;
            // cout << nT << " -> " << beta << " " << nT << "'" << endl;
            // cout << nT << "' -> " << alpha << " " << nT << "' | " << "ep" << endl;
        }
    }
    cout << "\n\n======= Final Grammar After Left Recursion Elimination =======" << endl;
    for (string &production : newGrammar)
        cout << production << endl;
}
