        // Author: Viveak | Fast CP Template for Codeforces
#include <bits/stdc++.h>
using namespace std;

// ========== DEBUGGING (turn off for submission) ==========
#ifdef LOCAL
    #define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
    #define debug(x)
#endif

void _print(int x) {cerr << x;}
void _print(long x) {cerr << x;}
void _print(long long x) {cerr << x;}
void _print(unsigned x) {cerr << x;}
void _print(unsigned long x) {cerr << x;}
void _print(unsigned long long x) {cerr << x;}
void _print(float x) {cerr << x;}
void _print(double x) {cerr << x;}
void _print(long double x) {cerr << x;}
void _print(char x) {cerr << '\'' << x << '\'';}
void _print(const char *x) {cerr << '\"' << x << '\"';}
void _print(const string &x) {cerr << '\"' << x << '\"';}
void _print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V> void _print(const pair<T, V> &x) {cerr << "{"; _print(x.first); cerr << ","; _print(x.second); cerr << "}";}
template<typename T> void _print(const vector<T> &x) {cerr << "["; for (auto &i : x) {_print(i); cerr << " ";} cerr << "]";}
template<typename T> void _print(const set<T> &x) {cerr << "["; for (auto &i : x) {_print(i); cerr << " ";} cerr << "]";}
template<typename T> void _print(const multiset<T> &x) {cerr << "["; for (auto &i : x) {_print(i); cerr << " ";} cerr << "]";}
template<typename T, typename V> void _print(const map<T, V> &x) {cerr << "["; for (auto &i : x) {_print(i); cerr << " ";} cerr << "]";}

// ========== MACROS & SHORTCUTS ==========
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define sz(x) (int)(x).size()
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = b - 1; i >= a; --i)

// ========== RANDOM GENERATOR ==========
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

// ========== MODULAR ARITHMETIC ==========
const int MOD = 1e9 + 7;
int mod_add(int a, int b) { return (a + b) % MOD; }
int mod_sub(int a, int b) { return (a - b + MOD) % MOD; }
int mod_mul(int a, int b) { return (a * b) % MOD; }
int mod_pow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mod_mul(res, a);
        a = mod_mul(a, a);
        b >>= 1;
    }
    return res;
}
int mod_inv(int a) { return mod_pow(a, MOD - 2); } // if MOD is prime

// ========== BIT MANIP ==========
#define setbits(x) __builtin_popcountll(x)
#define lz(x) __builtin_clzll(x)
#define tz(x) __builtin_ctzll(x)
#define parity(x) __builtin_parityll(x)

// ========== GRID DIRECTIONS ==========
const int dx[] = {-1, 0, 1, 0}; // up, right, down, left
const int dy[] = {0, 1, 0, -1};

// ========== POLICY BASED DS (Ordered Set) ==========
/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
*/

// ========== DSU ==========
/*
struct DSU {
    vi parent, size;
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(all(parent), 0);
    }
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        return true;
    }
};
*/

// ========== SEGMENT TREE PLACEHOLDER ==========
/*
struct SegmentTree {
    int n;
    vector<int> tree;
    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
    }
    void build(int node, int start, int end, vi &arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid, arr);
        build(2 * node + 1, mid + 1, end, arr);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
};
*/

// ========== MAIN SOLVER ==========
void solve() {
    int n, m, k;
        cin >> n >> m >> k;

        vector<string> g(n);
        for (auto& s : g) cin >> s;

        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
        int total = 0;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                int add = (g[i][j] == 'g');
                total += add;
                pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + add;
            }

        auto sum = [&](int x1, int y1, int x2, int y2) -> int {
            if (x1 > x2 || y1 > y2) return 0;
            return pref[x2 + 1][y2 + 1] - pref[x1][y2 + 1] - pref[x2 + 1][y1] + pref[x1][y1];
        };

        int ans = INT_MAX;
        int d = k - 1;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (g[i][j] == '.') {
                    int x1 = max(0, i - d);
                    int y1 = max(0, j - d);
                    int x2 = min(n - 1, i + d);
                    int y2 = min(m - 1, j + d);
                    ans = min(ans, sum(x1, y1, x2, y2));
                }

        cout << total - ans << '\n';
    return ;

}

int32_t main() {
    fastio();
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}

    