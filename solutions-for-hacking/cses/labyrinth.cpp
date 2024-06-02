/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/1193
 */

/*
 * Compile on windows powershell:
 * g++ --std=c++2a -DLOCAL .\template.cpp -o template.exe
 * 
 * Other cpp standards: c++11, c++14, c++20, etc.
 * 
 * Compile on unix based system terminal:
 * g++ --std=c++2a -DLOCAL template.cpp -o template.out
 */

// Include All Standard Template Library //
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

// Macro //
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

// Global //


// Functions //


// Main //
int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // cout << fixed << setprecision(15);

    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #else
    // online submission
    #endif

    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    // online submission
    #endif
    
    /* code */
    int n, m;
    cin >> n >> m;

    vector<string> laby(n);
    for (string &row : laby)
        cin >> row;
    
    vector<vector<int> > maze(n, vector<int>(m, INT_MAX));

    int a_i, a_j, b_i, b_j;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (laby[i][j] == 'A') {
                a_i = i;
                a_j = j;
            }

            if (laby[i][j] == 'B') {
                b_i = i;
                b_j = j;
            }
        }
    }

    maze[a_i][a_j] = 0;
    
    queue<pii> q;
    q.push({a_i, a_j});
    while (!q.empty()) {
        auto [i, j] = q.front();
        if (i + 1 < n && laby[i + 1][j] != '#' && maze[i + 1][j] > 1 + maze[i][j]) {
            maze[i + 1][j] = 1 + maze[i][j];
            q.push({i + 1, j});
        }

        if (j + 1 < m && laby[i][j + 1] != '#' && maze[i][j + 1] > 1 + maze[i][j]) {
            maze[i][j + 1] = 1 + maze[i][j];
            q.push({i, j + 1});
        }

        if (i > 0 && laby[i - 1][j] != '#' && maze[i - 1][j] > 1 + maze[i][j]) {
            maze[i - 1][j] = 1 + maze[i][j];
            q.push({i - 1, j});
        }

        if (j > 0 && laby[i][j - 1] != '#'  && maze[i][j - 1] > 1 + maze[i][j]) {
            maze[i][j - 1] = 1 + maze[i][j];
            q.push({i, j - 1});
        }

        q.pop();
    }

    if (maze[b_i][b_j] == INT_MAX) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    cout << maze[b_i][b_j] << '\n';

    string path;
    while (b_i != a_i || b_j != a_j) {
        if (b_i > 0 && maze[b_i][b_j] - 1 == maze[b_i - 1][b_j]) {
            path += 'D';
            b_i--;
            continue;
        }

        if (b_i + 1 < n && maze[b_i][b_j] - 1 == maze[b_i + 1][b_j]) {
            path += 'U';
            b_i++;
            continue;
        }

        if (b_j > 0 && maze[b_i][b_j] - 1 == maze[b_i][b_j - 1]) {
            path += 'R';
            b_j--;
            continue;
        }

        if (b_j + 1 < m && maze[b_i][b_j] - 1 == maze[b_i][b_j + 1]) {
            path += 'L';
            b_j++;
            continue;
        }
    }

    reverse(path.begin(), path.end());
    cout << path << endl;
    
    return 0;
}
