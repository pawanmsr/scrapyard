/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/1091
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
    int n, m, h_i;
    cin >> n >> m;

    map<ll, int> h;
    for (int i = 0; i < n; i++) {
        cin >> h_i;
        h[h_i]++;
    }
    
    vector<ll> t(m);
    for (ll &t_i : t)
        cin >> t_i;

    for (ll &t_i : t) {
        auto ub = h.upper_bound(t_i);
        if (ub == h.begin()) {
            cout << -1 << '\n';
        } else {
            ll ans = (*(--ub)).first;
            cout << ans << '\n';
            
            h[ans]--;
            if (!h[ans]) h.erase(ub);
        }
    }
    
    return 0;
}
