#include <bits/stdc++.h>
using namespace std;
int main()
{
    int vrtx, egs;
    cin >> vrtx >> egs;
    int adjM[vrtx][vrtx];
    memset(adjM, 0, sizeof(adjM));
    while (egs--)
    {
        int a, b;
        cin >> a >> b;
        adjM[a][b] = 1;
        adjM[b][a] = 1;
    }
    for (int i = 0; i < vrtx; i++)
    {
        for (int j = 0; j < vrtx; j++)
        {
            cout << adjM[i][j] << " ";
        }
        cout << endl;
    }
}
