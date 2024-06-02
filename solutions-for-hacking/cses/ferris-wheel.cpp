/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/1090
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
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int &a_i : a)
        cin >> a_i;
    
    sort(a.begin(), a.end());

    int i = 0;
    int j = n - 1;
    int gondolas = 0;
    while (i <= j) {
        while (i < j && a[i] + a[j] > x) {
            gondolas++;
            j--;
        }
        
        if (i < j) j--;
        gondolas++;
        i++;
    }

    cout << gondolas << endl;

    return 0;
}
