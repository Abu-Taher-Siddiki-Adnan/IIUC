#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "======= Simple Type Checking System =======" << endl;

    unordered_map<string, string> symbolTable;

    int choice;
    do
    {
        cout << "\n1. Declare Variable\n";
        cout << "2. Assign Value\n";
        cout << "3. Type Check Expression\n";
        cout << "4. Show Symbol Table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string varName, type;
            cout << "Enter variable name: ";
            cin >> varName;
            cout << "Enter type (int/float/char/bool): ";
            cin >> type;

            if (symbolTable.find(varName) != symbolTable.end())
                cout << "Error: Variable '" << varName << "' already declared!" << endl;
            else
            {
                symbolTable[varName] = type;
                cout << "Variable '" << varName << "' declared as type: " << type << endl;
            }
            break;
        }

        case 2:
        {
            string varName, value;
            cout << "Enter variable name: ";
            cin >> varName;

            if (symbolTable.find(varName) == symbolTable.end())
            {
                cout << "Error: Variable '" << varName << "' not declared!" << endl;
                break;
            }

            cout << "Enter value to assign: ";
            cin.ignore();
            getline(cin, value);

            string varType = symbolTable[varName];

            bool valid = false;

            if (varType == "int")
            {
                bool isInt = true;
                for (char c : value)
                {
                    if (!isdigit(c) && c != '-' && c != '+')
                    {
                        isInt = false;
                        break;
                    }
                }
                if (isInt)
                    valid = true;
            }
            else if (varType == "float")
            {
                bool isFloat = true;
                bool dotFound = false;
                for (char c : value)
                {
                    if (!isdigit(c))
                    {
                        if (c == '.' && !dotFound)
                        {
                            dotFound = true;
                        }
                        else if (c != '-' && c != '+')
                        {
                            isFloat = false;
                            break;
                        }
                    }
                }
                if (isFloat)
                    valid = true;
            }
            else if (varType == "char")
            {
                if (value.length() == 1)
                    valid = true;
            }
            else if (varType == "bool")
            {
                if (value == "true" || value == "false" || value == "0" || value == "1")
                    valid = true;
            }

            if (valid)
            {
                cout << "Value '" << value << "' assigned to '" << varName << "' successfully!" << endl;
            }
            else
            {
                cout << "Type Error: Cannot assign value '" << value << "' to variable of type '" << varType << "'!" << endl;
            }
            break;
        }

        case 3:
        {
            string expr;
            cout << "Enter simple expression (e.g., a + b): ";
            cin.ignore();
            getline(cin, expr);

            string cleanExpr = "";
            for (char c : expr)
            {
                if (c != ' ')
                    cleanExpr += c;
            }

            string var1 = "", var2 = "";
            char op = ' ';
            bool foundOp = false;

            for (char c : cleanExpr)
            {
                if ((c == '+' || c == '-' || c == '*' || c == '/') && !foundOp)
                {
                    op = c;
                    foundOp = true;
                }
                else
                {
                    if (!foundOp)
                        var1 += c;
                    else
                        var2 += c;
                }
            }

            if (!foundOp || var1.empty() || var2.empty())
            {
                cout << "Invalid expression format! Use: variable operator variable" << endl;
                break;
            }

            if (symbolTable.find(var1) == symbolTable.end())
            {
                cout << "Error: Variable '" << var1 << "' not declared!" << endl;
                break;
            }
            if (symbolTable.find(var2) == symbolTable.end())
            {
                cout << "Error: Variable '" << var2 << "' not declared!" << endl;
                break;
            }

            string type1 = symbolTable[var1];
            string type2 = symbolTable[var2];

            if (type1 == type2)
            {
                cout << "Type Check PASSED: " << var1 << " (" << type1 << ") " << op << " " << var2 << " (" << type2 << ")" << endl;
                cout << "Result type: " << type1 << endl;
            }
            else if ((type1 == "int" && type2 == "float") || (type1 == "float" && type2 == "int"))
            {
                cout << "Type Check PASSED with implicit conversion" << endl;
                cout << var1 << " (" << type1 << ") " << op << " " << var2 << " (" << type2 << ")" << endl;
                cout << "Result type: float" << endl;
            }
            else if ((type1 == "int" && type2 == "char") || (type1 == "char" && type2 == "int"))
            {
                cout << "Type Check PASSED with implicit conversion" << endl;
                cout << var1 << " (" << type1 << ") " << op << " " << var2 << " (" << type2 << ")" << endl;
                cout << "Result type: int" << endl;
            }
            else
            {
                cout << "Type Check FAILED: Incompatible types!" << endl;
                cout << var1 << " is " << type1 << ", but " << var2 << " is " << type2 << endl;
                cout << "Cannot perform operation: " << op << endl;
            }
            break;
        }

        case 4:
        {
            cout << "\n======= Symbol Table =======" << endl;
            if (symbolTable.empty())
            {
                cout << "No variables declared yet!" << endl;
            }
            else
            {
                for (auto &entry : symbolTable)
                {
                    cout << entry.first << " : " << entry.second << endl;
                }
            }
            break;
        }

        case 5:
            cout << "Exiting Type Checking System..." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}