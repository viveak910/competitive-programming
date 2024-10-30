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

// Debugging (comment out in production)
#define dbg(x) cerr << #x << " = " << (x) << endl;

int main() {
    fastIO();

    int t = 1;
    // cin >> t; // Uncomment if multiple test cases
    while (t--) {
    int  x = 0, y, n, sol = 0,energy = 0;
    cin >> n;
    for(int i = 1;i <= n; ++i)
    {
        cin >> y;
        energy += x-y;
        if(energy < 0){
            sol += -energy;
            energy = 0;
        }
        x = y;
    }
    cout<<sol<<"\n";
    }

    return 0;
}
