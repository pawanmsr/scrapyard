/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/1071
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
    int t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> y >> x;

        ll i = 0;
        while (i + 1 < max(x, y))
            i++;
        
        bool acw = (i % 2 == 0);
        if (acw) {
            if (y >= x) cout << (i * i) + x << endl;
            else cout << (i * i) + 2 * (i + 1) - y << endl;
        } else {
            if (x >= y) cout << (i * i) + y << endl;
            else cout << (i * i) + 2 * (i + 1) - x << endl;
        }
    }
    
    return 0;
}
