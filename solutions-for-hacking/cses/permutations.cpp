/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/1070
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

    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }

    if (n < 4) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    for (int i = (n % 2 ? n : n - 1); i > 0; i-=2)
        cout << i << ' ';
    for (int i = (n % 2 ? n - 1 : n); i > 0; i-=2)
        cout << i << ' ';
    cout << endl;
    
    return 0;
}
