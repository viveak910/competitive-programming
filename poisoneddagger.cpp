#include <bits/stdc++.h>
using namespace std;

// Shortcuts for data types
#define ll long long
#define ull unsigned long long
#define ld long double

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

// Faster I/O
void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

// Helper function to check if a given `mid` can cover height `h`
bool canAchieveHeight(ll n, ll h, vector<ll>& seconds, ll mid) {
    ll sum = 0;
    for (int i = 0; i < n - 1; i++) {
        if (mid > seconds[i + 1] - seconds[i]) {
            sum += seconds[i + 1] - seconds[i];
        } else {
            sum += mid;
        }
    }
    sum += mid;  // Add the final segment
    return sum >= h;
}

int main() {
    fastIO();
    
    int t;
    cin >> t;
    while (t--) {
        ll n, h;
        cin >> n >> h;
        vector<ll> seconds(n);
        
        for (int i = 0; i < n; i++) {
            cin >> seconds[i];
        }
        
        ll left = 1, right = LINF;
        ll ans = 0;
        
        // Binary search to find the minimum `mid` value
        while (left <= right) {
            ll mid = left + (right - left) / 2;
            if (canAchieveHeight(n, h, seconds, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
