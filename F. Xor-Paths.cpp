#include<bits/stdc++.h>
using namespace std; 
#define ll long long; 
vector<ll>v;
vector<vector<ll>>visited(n,vector<ll>(m,0));
static int count =0 ; 
void bfs(int i ,int j ,int k, int xor ,vector<vector<ll>>v1(n,vector<ll>(m,0)),int n , int m){
	if(((xor^v1[i][j])==k)&&(i==n-1&&j==m-1)){
		count++;
		return ; 
	}
	if(i<0&&j<0&&i>=n&&j>=m&&){
		return ;
	}
	bfs(i+1,j,k,xor^a[i][j],v1,n,m);
	bfs(i,j+1,k,xor^a[i][j],v1,n,m);

}
int main(){
	ll n , m , k ; 
	cin >> n >> m >> k ; 
	vector<vector<ll>>v1(n,vector<ll>(m));
	for(ll i=0 ; i< n ; i++){
		for(ll j =0 ; j<m ; j++){
			cin >> v1[i][j];
		}
	}
	bfs(i,j,k,0,v1,n,m);
	cout << count << endl;
	return 0 ;
}