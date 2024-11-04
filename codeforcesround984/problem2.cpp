#include <bits/stdc++.h>
using namespace std;

// Shortcuts for data types
#define ll long long
#define ull unsigned long long
#define ld long double

// Shortcuts for common functions
#define pb push_back
#define mp make_pair
#define fi first
#define se second

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

// Utility functions
template<typename T> void read(T &x) { cin >> x; }
template<typename T> void write(T x) { cout << x << ' '; }
template<typename T> void writeln(T x) { cout << x << '\n'; }

// Faster I/O
void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fastIO();

    int t = 1;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            m[x].pb(y);
        }

        vector<int> v;
        for (auto &x : m) {
            v.pb(accumulate(x.se.begin(), x.se.end(), 0));
        }
    
        sort(v.begin(), v.end(), greater<int>());

        int sum = 0;
        for (int i = 0; i < min(n, (int)v.size()); i++) {
            sum += v[i];
        }
        cout << sum << endl;
    }

    return 0;
}
