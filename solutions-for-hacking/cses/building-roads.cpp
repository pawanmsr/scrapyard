/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/1666
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
void dfs(int u, vector<vector<int> > &g, vector<int> &component, const int k) {
    component[u] = k;
    for (int v : g[u]) {
        if (component[v] != -1) continue;

        dfs(v, g, component, k);
    }
}

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

    vector<vector<int> > g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> component(n, -1);
    for (int i = 0; i < n; i++) {
        if (component[i] != -1) continue;
        
        dfs(i, g, component, i);
    }

    set<int> sources;
    for (int c : component)
        sources.insert(c);

    int prev = -1;
    cout << sources.size() - 1 << '\n';
    for (const int &s : sources) {
        if (prev >= 0 && prev != s)
            cout << prev + 1 << ' ' << s + 1 << '\n';
        prev = s;
    }
    
    return 0;
}
