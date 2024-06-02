/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/1640
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
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int &a_i : a)
        cin >> a_i;
    
    map<int, int> check;
    bool possible = false;
    for (int i = 0; i < n; i++) {
        if (check.find(x - a[i]) != check.end()) {
            possible = true;
            cout << check[x - a[i]] + 1 << ' ' << i + 1 << '\n';
            break;
        }

        check[a[i]] = i;
    }

    if (!possible)
        cout << "IMPOSSIBLE\n";
    
    return 0;
}
