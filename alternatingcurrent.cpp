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

int main() {
    fastIO();

   int t =1;
   //cin>>t;

    while (t--) {
        string s ; 
        cin >> s ; 
        stack<char> st ;
        // if(s.size()==1 && s[0]=='+'){
        //     cout << "YES" << endl;
        //     continue ; 
        // }
        st.push(s[0]) ;
        for(int i = 1 ; i< s.size() ; i++){
            if(st.empty()){
                st.push(s[i]) ;
            }else{
                if(st.top() == s[i]){
                    st.pop() ;
                }else{
                    st.push(s[i]) ;
                }
            }
        }
        if(st.empty()){
            cout << "Yes" << endl ;
        }else{
            cout << "No" << endl ;
        }

    }

    return 0;
}
