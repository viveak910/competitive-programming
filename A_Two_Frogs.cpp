#include <bits/stdc++.h>
using namespace std;

bool can_alice_win(int n, int alice, int bob) {
    if (abs(alice - bob) == 1) {
        // If frogs are adjacent
        if (alice < bob && alice == 1) return false;  // Alice trapped at left
        if (alice > bob && alice == n) return false;  // Alice trapped at right
    }
    
    // Key insight: This is about who has enough moves to control the game
    if (alice < bob) {
        // If there's enough space for Bob to move right, he can't be trapped
        return n - bob < bob - alice;
    } else {
        // If there's enough space for Bob to move left, he can't be trapped
        return bob - 1 < alice - bob;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
        cout << (can_alice_win(n, a, b) ? "YES\n" : "NO\n");
    }
    return 0;
}