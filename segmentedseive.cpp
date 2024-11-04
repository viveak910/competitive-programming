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
vector<ll> primeseive(ll limit){
    vector<bool> primes(limit+1,true);
    vector<ll> prime;
    for(ll i =2 ;i<=limit;i++){
        if(primes[i]){
            prime.pb(i);
            for(ll j = i*i;j<=limit;j+=i){
                primes[j] = false;
            }
        }

    }
    return prime;
}
vector<ll>segmented(ll l, ll r){
    vector<ll>prime = primeseive(sqrt(r));
    vector<bool>isprime(r-l+1,true);
    for(ll p: prime){
        if(p*p<=r){
            for(ll i = max(p*p,(l+p-1)/p*p);i<=r;i+=p){
                isprime[i-l] = false;
            }
        }
    }
    vector<ll>segmentedprime;
    for(ll i = max(l,2ll);i<=r;i++){
        if(isprime[i-l]){
            segmentedprime.pb(i);
        }
    }
    return segmentedprime;
}

int main() {
    fastIO();

   int t =1;
   cin>>t;

    while (t--) {
        ll l, r ;
        cin>>l>>r; 
        vector<ll>primes = segmented(l,r);
        for(ll p: primes){
            cout<<p<<" ";
        }
        cout<<endl;
        

    }

    return 0;
}
