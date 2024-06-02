/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/1629
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
    ll n;
    cin >> n;

    vector<pii> ab(n);
    for (pii &ab_i : ab) {
        cin >> ab_i.X >> ab_i.Y;
    }

    sort(ab.begin(), ab.end(), [&](pii &x, pii &y) {
        if (x.Y != y.Y) return x.Y < y.Y;
        else return x.X < y.X;
    });

    int end = 0;
    int ans = 0;
    for (pii &ab_i : ab) {
        if (ab_i.X >= end) {
            end = ab_i.Y;
            ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}
