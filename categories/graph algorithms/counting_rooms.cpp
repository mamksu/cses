#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> grid;
int n, m;
vector<int> di = {-1, 0, 0, 1};
vector<int> dj = {0, -1, 1, 0};
void dfs(int i, int j)
{
    grid[i][j] = '#';
    for (int k = 0; k < 4; ++k)
    {
        int si = i + di[k];
        int sj = j + dj[k];
        if (si >= 0 && sj >= 0 && si < n && sj < m && grid[si][sj] == '.')
            dfs(si, sj);
    }
    return;
}
inline void print()
{
    for (auto x : grid)
    {
        for (char y : x)
            cout << y;
        cout << "\n";
    }
    cout << "\n";
}
signed main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        vector<char> temp;
        for (int j = 0; j < m; ++j)
        {
            char x;
            cin >> x;
            temp.push_back(x);
        }
        grid.push_back(temp);
    }

    // cout << "\n";
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == '.')
            {
                dfs(i, j);
                // print();
                ++cnt;
            }
        }
    }
    cout << cnt;
}