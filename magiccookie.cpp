 #include <bits/stdc++.h>
using namespace std;

#define ll long long

void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool canbake(ll n, ll k, const vector<ll>& need, const vector<ll>& have, ll mid) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll required = need[i] * mid;
        if (required > have[i]) {
            sum += required - have[i];
            if (sum > k) {
                return false;
            }
        }
    }
    return sum <= k;
}

int main() {
    fastIO();

    int t = 1;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> need(n), have(n);

        for (int i = 0; i < n; i++) {
            cin >> need[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> have[i];
        }
        ll left = 0, right = 2e9, ans = 0;
        while (left <= right) {
            ll mid = left + (right - left) / 2;
            if (canbake(n, k, need, have, mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
