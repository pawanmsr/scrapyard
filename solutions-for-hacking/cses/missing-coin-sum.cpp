/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/2183
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

    vector<ll> x(n);
    for (ll &x_i : x)
        cin >> x_i;
    
    sort(x.begin(), x.end());
    
    ll sum = 0LL;
    ll smallest = 1;
    for (int x_i : x) {
        sum += x_i;
        
        if (x_i <= smallest)
            smallest = max(smallest + 1, sum + 1);
    }

    cout << smallest << endl;
    
    return 0;
}
