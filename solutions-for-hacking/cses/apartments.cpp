/*
 * Problem Statement
 * https://cses.fi/problemset/task/1084
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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int &a_i : a)
        cin >> a_i;
    
    for (int &b_i : b)
        cin >> b_i;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0;
    int j = 0;
    vector<pii> allocation;
    while (i < n && j < m) {
        while (i < n && a[i] < b[j] - k) i++;
        while (j < m && b[j] < a[i] - k) j++;

        if (i < n && j < m && abs(a[i] - b[j]) <= k) {
            allocation.push_back({a[i++], b[j++]});
        }
    }

    cout << allocation.size() << endl;

    return 0;
}
