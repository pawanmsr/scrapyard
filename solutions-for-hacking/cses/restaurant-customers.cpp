/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/1619
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

    vector<ll> arrival(n);
    vector<ll> departure(n);
    for(int i = 0; i < n; i++) {
        cin >> arrival[i];
        cin >> departure[i];
    }
    
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int i = 0;
    int j = 0;
    int ans = 0;
    int count = 0;
    while (i < n) {
        if (arrival[i] <= departure[j]) {
            count++;
            i++;
        } else {
            count--;
            j++;
        }

        ans = max(ans, count);
    }

    cout << ans << endl;
    
    return 0;
}
