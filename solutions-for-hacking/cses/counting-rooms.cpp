/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/1192
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
void traverse(int i, int j, const int n, const int m, 
    vector<string> &s, vector<vector<int> > &assign, int room) {
        assign[i][j] = room;
        if (i - 1 >= 0 && s[i - 1][j] == '.' && assign[i - 1][j] == INT_MAX)
            traverse(i - 1, j, n, m, s, assign, room);
        
        if (j - 1 >= 0 && s[i][j - 1] == '.' && assign[i][j - 1] == INT_MAX)
            traverse(i, j - 1, n, m, s, assign, room);

        if (i + 1 < n && s[i + 1][j] == '.' && assign[i + 1][j] == INT_MAX)
            traverse(i + 1, j, n, m, s, assign, room);
        
        if (j + 1 < m && s[i][j + 1] == '.' && assign[i][j + 1] == INT_MAX)
            traverse(i, j + 1, n, m, s, assign, room);
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
    
    /* code */
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (string &s_i : s)
        cin >> s_i;
    
    vector<vector<int> > assign(n, vector<int>(m, INT_MAX));
    
    int room = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') continue;
            if (assign[i][j] != INT_MAX) continue;

            traverse(i, j, n, m, s, assign, room);
            room++;
        }
    }

    cout << room - 1 << endl;
    
    return 0;
}
