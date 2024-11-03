//problemlink: https://codeforces.com/contest/371/problem/C

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

// Function to check if we can make `ham` hamburgers with the given budget and ingredients
bool maxHamburgers(ll ham, ll nb, ll ns, ll nc, ll pb, ll ps, ll pc, ll r, unordered_map<char, ll>& recipe) {
    // Calculate the extra ingredients needed
    ll needB = max(0LL, recipe['B'] * ham - nb);
    ll needS = max(0LL, recipe['S'] * ham - ns);
    ll needC = max(0LL, recipe['C'] * ham - nc);

    // Calculate total cost for extra ingredients
    ll totalCost = needB * pb + needS * ps + needC * pc;

    // Check if total cost is within budget
    return totalCost <= r;
}

int main() {
    fastIO();

    string recipeString;
    cin >> recipeString;
    
    ll nb, ns, nc; // Available quantities of bread, sausage, and cheese
    cin >> nb >> ns >> nc;
    
    ll pb, ps, pc; // Prices of bread, sausage, and cheese
    cin >> pb >> ps >> pc;
    
    ll r; // Available rubles
    cin >> r;

    // Count the ingredients required for one hamburger
    unordered_map<char, ll> recipe;
    for (char ingredient : recipeString) {
        recipe[ingredient]++;
    }

    // Binary search to maximize the number of hamburgers
    ll left = 0, right = 1e13, maxHamburgersCount = 0;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        
        if (maxHamburgers(mid, nb, ns, nc, pb, ps, pc, r, recipe)) {
            // If we can make `mid` hamburgers, try for more
            maxHamburgersCount = mid;
            left = mid + 1;
        } else {
            // If we cannot make `mid` hamburgers, try less
            right = mid - 1;
        }
    }

    cout << maxHamburgersCount << endl;
    
    return 0;
}
