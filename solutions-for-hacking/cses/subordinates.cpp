/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/1674
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


// Main //
int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // cout << fixed << setprecision(15);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #else
    // online submission
    #endif
    
    /* code */
    int n;
    cin >> n;

    vector<int> a(n, 0);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> ans(n, -1);
    vector<vector<int> > subs(n);
    for (int i = 1; i < n; i++)
        subs[a[i]].push_back(i);
    
    stack<int> s;
    s.push(0);
    while (!s.empty()) {
        int p = s.top();
        for (int c : subs[p])
            if (ans[c] == -1) {
                if (subs[c].size() == 0)
                    ans[c] = 0;
                else s.push(c);
            }
        
        if (p != s.top())
            continue;
        s.pop();
        
        int count = 0;
        for (int c : subs[p]) {
            count += 1 + ans[c];
        }
        ans[p] = count;
    }

    for (int ans_i : ans)
        cout << ans_i << ' ';
    cout << '\n';
    
    return 0;
}
