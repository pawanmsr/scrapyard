/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/1755
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
    string s;
    cin >> s;

    map<char, int> m;
    for (char s_i : s) {
        m[s_i]++;
    }

    int odds = 0;
    for (auto m_i : m) {
        if (m_i.second % 2)
            odds++;
    }

    if (odds > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    int i = 0;
    const int n = s.length();
    for (auto &m_i : m) {
        while (m_i.second > 1) {
            s[i] = m_i.first;
            s[n - 1 - i] = m_i.first;
            m_i.second -= 2;

            i++;
        }

        if (m_i.second == 1) {
            s[n / 2] = m_i.first;
            m_i.second--;
        }
    }

    cout << s << endl;

    return 0;
}
