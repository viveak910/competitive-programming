#include<bits/stdc++.h>
using namespace std; 
int main(){
    int t ; 
    cin >> t ; 
    while(t--){
        int n , x ; 
        cin >> n >> x ;
        if(x%2==0){
            cout << n/2 -1 << endl ; 
        } 
        else{
            cout <<(n%2==1?(n+1)/2-1 : n/2-1) << endl ;
        }
    }
    return 0 ;
}