/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/2431
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
ll fast_exp(ll x, ll y) {
    if (y == 0) return 1;
    if (y == 1) return x;

    if (x == 0 || x == 1)
        return x;
    
    return (y % 2 ? x * fast_exp(x * x, y / 2) : fast_exp(x * x, y / 2));
}

vector<int> get_digs(ll q) {
    vector<int> ans;
    while (q) {
        ans.push_back(q % 10);
        q /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
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
    int q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;

        ll i = 1;
        while (9 * fast_exp(10, i - 1) * i < k) {
            k -= 9 * fast_exp(10, i - 1) * i;
            i++;
        }

        ll p = fast_exp(10, i - 1) + (k - 1) / i;

        ll idx = (k + i - 1) % i;

        vector<int> d = get_digs(p);
        cout << d[idx] << '\n';
    }

    return 0;
}
