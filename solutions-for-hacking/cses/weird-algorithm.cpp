/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/1068
 */

/*
 * Compile on windows powershell:
 * g++ --std=c++2a .\template.cpp -o template.exe
 * 
 * Other cpp standards: c++11, c++14, c++20, etc.
 * 
 * Compile on unix based system terminal:
 * g++ --std=c++2a template.cpp -o template.out
 */

// Include Standard Template Library //
// #include <iostream>
// #include <iomanip>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <queue>
// #include <deque>
// #include <bitset>
// #include <iterator>
// #include <list>
// #include <stack>
// #include <map>
// #include <set>
// #include <functional>
// #include <numeric>
// #include <utility>
// #include <limits>
// #include <fstream>
// #include <cstring>
// #include <unordered_set>
// #include <unordered_map>

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
    
    /* code */
    ll n;
    cin >> n;

    while (n >= 1) {
        cout << n << ' ';
        if (n == 1) break;

        if (n % 2 == 0) n/=2;
        else n = n * 3 + 1;
    }
    
    return 0;
}
