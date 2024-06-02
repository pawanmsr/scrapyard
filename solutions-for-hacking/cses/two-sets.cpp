/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/1092
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

    if ((n * (n + 1) / 2) % 2) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    set<int> a, b;
    ll m = n;
    while (m) {
        a.insert(m--);
        if (m) b.insert(m--);
        if (m) b.insert(m--);
        if (m) a.insert(m--);
    }

    cout << a.size() << '\n';
    for (int a_i : a)
        cout << a_i << ' ';
    cout << endl;
    
    cout << b.size() << '\n';
    for (int b_i : b)
        cout << b_i << ' ';
    cout << endl;
    
    return 0;
}
