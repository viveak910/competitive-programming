#include <bits/stdc++.h>
using namespace std;

void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool is1100(const string& s, int i) {
    return i >= 0 && i + 3 < s.size() && s.substr(i, 4) == "1100";
}

int main() {
    fastIO();

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int q;
        cin >> q;

        int count = 0;
        int n = s.size();
        for (int i = 0; i <= n - 4; i++) {
            if (is1100(s, i)) {
                count++;
            }
        }


        while (q--) {
            int l;
            char r;
            cin >> l >> r;
            l--; 
            for (int i = l - 3; i <= l; i++) {
                if (is1100(s, i)) {
                    count--;
                }
            }
            s[l] = r;
            for (int i = l - 3; i <= l; i++) {
                if (is1100(s, i)) {
                    count++;
                }
            }
            cout << (count > 0 ? "YES" : "NO") << endl;
        }
    }

    return 0;
}
