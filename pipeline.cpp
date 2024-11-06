#include <bits/stdc++.h>
using namespace std;

// Shortcuts for data types
#define ll long long

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

// Sum of the first `x` natural numbers
ll sum(ll x) {
    return (x * (x + 1)) / 2;
}

int main() {
    fastIO();

    int testCases = 1;
    // cin >> testCases; // Uncomment this line if there are multiple test cases

    while (testCases--) {
        ll n, k;
        cin >> n >> k;
        
        
        ll totalSum = sum(k - 1); // Sum of numbers from 1 to (k-1)
        n -= 1; // Adjust n since we assume we're not counting the '1' already picked

        if (totalSum < n) {
            cout << -1 << endl;
            continue;
        }
        
        
        // Binary search to find the minimum 'x' where sum from 2 to x >= n
        ll left = 0, right = k - 1;
        
        while (left <= right) {
            ll mid = left+(right-left) / 2;
            if ((totalSum-sum(mid)) >= n) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        
        cout << k-1-right << endl;
    }

    return 0;
}
