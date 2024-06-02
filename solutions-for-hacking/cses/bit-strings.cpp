/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/1617
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
const ll mod = 1e9 + 7;

// Functions //
ll fast_exp(ll x, ll y) {
    if (y == 1) return x;
    if (x == 1 || x == 0) return x;

    if (y % 2) return ((x * fast_exp((x * x) % mod, y / 2)) % mod);
    else return (fast_exp((x * x) % mod, y / 2) % mod);
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
    ll n;
    cin >> n;

    cout << (fast_exp(2, n) % mod) << endl;
    
    return 0;
}
