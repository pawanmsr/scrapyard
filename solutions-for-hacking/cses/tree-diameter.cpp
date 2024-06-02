/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/1131
 */

/*
 * Compile on windows powershell:
 * g++ -DLOCAL --std=c++2a .\template.cpp -o template.exe
 * 
 * Other cpp standards: c++11, c++14, c++20, etc.
 * 
 * Compile on unix based system terminal:
 * g++ --std=c++2a template.cpp -o template.out
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
void dfs(int u, vector<vector<int> > &tree, vector<int> &depth) {
    for (int v : tree[u]) {
        if (depth[v] != INT_MIN)
            continue;

        depth[v] = depth[u] + 1;
        dfs(v, tree, depth);
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
    int n, a, b;
    cin >> n;

    vector<vector<int> > tree(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a--; b--;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<int> depth(n, INT_MIN);

    depth[0] = 0;
    dfs(0, tree, depth);
    
    int node = -1;
    int max_depth = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (depth[i] <= max_depth)
            continue;
        
        max_depth = depth[i];
        node = i;
    }

    for (int &d : depth)
        d = INT_MIN;
    
    depth[node] = 0;
    dfs(node, tree, depth);

    cout << *max_element(depth.begin(), depth.end()) << endl;
    
    return 0;
}
