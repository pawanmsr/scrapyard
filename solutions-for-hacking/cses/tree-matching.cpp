/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/1130
 */

/*
 * Compile on windows powershell:
 * g++ --std=c++2a .\template.cpp -o template.exe
 * 
 * Other cpp standards: c++11, c++14, c++20, etc.
 * 
 * Compile on unix based system terminal:
 * g++ --std=c++2a template.cpp -o template.out
 */

// Include Standard Template Library //
// #include <iostream>
// #include <iomanip>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <queue>
// #include <deque>
// #include <bitset>
// #include <iterator>
// #include <list>
// #include <stack>
// #include <map>
// #include <set>
// #include <functional>
// #include <numeric>
// #include <utility>
// #include <limits>
// #include <fstream>
// #include <cstring>
// #include <unordered_set>
// #include <unordered_map>

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
void compute(int node, int parent, const vector<vector<int> > &tree, vector<vector<int> > &dp) {
    if (tree[node].size() == 1) {
        dp[node][1] = 0;
        dp[node][0] = 0;
    }
    
    int sum = 0;
    for (int v : tree[node]) {
        if (v == parent) continue;
        
        compute(v, node, tree, dp);
        sum += max(dp[v][0], dp[v][1]);
    }
    dp[node][0] = sum;

    for (int v : tree[node]) {
        if (v == parent) continue;
        
        dp[node][1] = max(dp[node][1], 1 + dp[v][0] + dp[node][0] - max(dp[v][0], dp[v][1]));
    }
}

// Main //
int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // cout << fixed << setprecision(15);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    // online submission
    #endif
    
    /* code */
    int n, x, y;
    cin >> n;

    vector<vector<int> > tree(n);
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        x--; y--;

        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    vector<vector<int> > dp(n, vector<int>(2, -1));
    compute(0, -1, tree, dp);
    cout << max(dp[0][0], dp[0][1]) << endl;

    return 0;
}
