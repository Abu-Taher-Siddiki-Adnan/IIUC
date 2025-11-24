#include <bits/stdc++.h>
using namespace std;

bool isAlphaNum(char c) { return isalnum(static_cast<unsigned char>(c)); }

bool isValidLocal(const string &local)
{
    if (local.empty())
        return false;
    // allowed chars: A-Z a-z 0-9 . _ % + -
    auto allowed = [](char c)
    {
        return isalnum(static_cast<unsigned char>(c)) || c == '.' || c == '_' || c == '%' || c == '+' || c == '-';
    };
    if (!allowed(local[0]) || !allowed(local.back()))
        return false;
    if (local.front() == '.' || local.back() == '.')
        return false;
    for (size_t i = 0; i < local.size(); ++i)
    {
        char c = local[i];
        if (!allowed(c))
            return false;
        // no consecutive dots
        if (c == '.' && i + 1 < local.size() && local[i + 1] == '.')
            return false;
    }
    return true;
}

bool isValidDomain(const string &dom)
{
    if (dom.empty())
        return false;
    // domain must contain at least one dot separating name and TLD
    size_t pos = dom.find('.');
    if (pos == string::npos)
        return false;
    // split by dots
    vector<string> labels;
    size_t start = 0;
    while (start < dom.size())
    {
        size_t p = dom.find('.', start);
        if (p == string::npos)
            p = dom.size();
        string label = dom.substr(start, p - start);
        if (label.empty())
            return false; // empty label invalid
        labels.push_back(label);
        start = p + 1;
    }
    // validate each label (only letters, digits, hyphen), can't start or end with '-'
    for (size_t i = 0; i < labels.size(); ++i)
    {
        const string &lab = labels[i];
        if (lab.front() == '-' || lab.back() == '-')
            return false;
        for (char c : lab)
        {
            if (!(isAlphaNum(c) || c == '-'))
                return false;
        }
    }
    // TLD (last label) must be at least 2 letters and contain only letters
    const string &tld = labels.back();
    if (tld.size() < 2)
        return false;
    for (char c : tld)
        if (!isalpha(static_cast<unsigned char>(c)))
            return false;
    return true;
}

bool isValidEmail(const string &s)
{
    // basic checks: exactly one '@', splits into local@domain
    size_t at = s.find('@');
    if (at == string::npos)
        return false;
    if (s.find('@', at + 1) != string::npos)
        return false; // multiple @
    string local = s.substr(0, at);
    string domain = s.substr(at + 1);
    if (!isValidLocal(local))
        return false;
    if (!isValidDomain(domain))
        return false;
    return true;
}

int main()
{
    string s;
    while (cin >> s)
    {
        if (isValidEmail(s))
            cout << "'" << s << "' is a valid email." << endl;
        else
            cout << "'" << s << "' is an invalid email." << endl;
    }
    return 0;
}
