/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/1074
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
    int n;
    cin >> n;

    vector<ll> p(n);
    for (ll &p_i : p)
        cin >> p_i;
    
    sort(p.begin(), p.end());
    
    ll ans = accumulate(p.begin(), p.end(), 0LL);
    for (int i = (n - 1) / 2; i <= n / 2; i++) {
        ll median = p[i];
        
        ll curr = 0;
        for (ll &p_i : p)
            curr += abs(p_i - median);
        
        ans = min(ans, curr);
    }

    cout << ans << endl;

    return 0;
}
