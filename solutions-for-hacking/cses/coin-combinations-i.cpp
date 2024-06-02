/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/1635
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

    const int mod = 1e9 + 7;

    vector<int> c(n);
    for (int &c_i : c)
        cin >> c_i;
    
    sort(c.begin(), c.end());
    
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < x; i++) {
        for (int &c_i : c) {
            if (i + c_i <= x)
                dp[i + c_i] = (dp[i + c_i] + dp[i]) % mod;
        }
    }
    
    cout << dp[x] << endl;
    
    return 0;
}
