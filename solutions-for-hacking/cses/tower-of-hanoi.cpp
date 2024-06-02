/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/2165
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
int fast_exp(int x, int y) {
    if (y == 0) return 1;
    if (y == 1) return x;

    if (x == 0 || x == 1)
        return x;

    if (y % 2) return x * fast_exp(x * x, y / 2);
    return fast_exp(x * x, y / 2);
}

void tower_of_hanoi(int n, int from, int aux, int to) {
    if (n == 1) {
        cout << from << ' ' << to << '\n';
    } else {
        tower_of_hanoi(n - 1, from, to, aux);
        cout << from << ' ' << to << '\n';
        tower_of_hanoi(n - 1, aux, from, to);
    }
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
    int n;
    cin >> n;

    cout << fast_exp(2, n) - 1 << '\n';
    tower_of_hanoi(n, 1, 2, 3);
    
    return 0;
}
