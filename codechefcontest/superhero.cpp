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
int find_largest_divisor(int n) {
    if (n % 2 == 0) return n / 2;
    for (int i = sqrt(n); i >= 1; i--) {
        if (n % i == 0) {
            return max(i, n / i);  
        }
    }
    return 1;
}


int main() {
    fastIO();

    int t;
    cin >> t;

    while (t--) {
        int h, m;
        cin >> h >> m;
        int maxmon= 0 ;
        for(int i =1 ; i<m+1;i++){
            int health = h*i;
            int count=0;
            while(health>1){
                int divisor = find_largest_divisor(health);
                health = divisor;
                count++;
            }
            maxmon= max(maxmon,count);
            
        }
        cout << maxmon << endl;
    }

    return 0;
}
