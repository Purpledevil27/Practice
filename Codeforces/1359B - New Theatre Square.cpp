#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        char a[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        y = min(y, 2 * x);
        int cost = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == '.' && j + 1 < m && a[i][j + 1] == '.')
                {
                    cost += y;
                    a[i][j] = '*';
                    a[i][j + 1] = '*';
                }
                else if (a[i][j] == '.')
                {
                    cost += x;
                    a[i][j] == '*';
                }
            }
        }
        cout << cost << endl;
    }
}
