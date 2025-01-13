#include <bits/stdc++.h>
using namespace std;

bool canMakeNonDecreasing(vector<int>& a, int n, int m, int ops) {
    int prev = 0;
    for (int i = 0; i < n; ++i) {
        int curr = a[i];
        
        // Check if we can make current element >= prev with `ops` operations
        if (curr < prev) {
            // curr is too small, increase it by wrapping around up to `ops` times
            if (curr + ops < prev) return false;  // Not enough to reach prev
        } else if (curr <= prev + ops) {
            // curr can be adjusted within `ops` to satisfy the non-decreasing condition
            continue;
        } else {
            // curr is too large and cannot be adjusted downward to fit
            return false;
        }
        
        // Update prev to the adjusted current element for next iteration
        prev = curr;
    }
    return true;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    
    int left = 0, right = m;
    while (left < right) {
        int mid = (left + right) / 2;
        if (canMakeNonDecreasing(a, n, m, mid)) {
            right = mid;  // Try for fewer operations
        } else {
            left = mid + 1;  // Need more operations
        }
    }
    cout << left << endl;  // Minimum operations required
}
