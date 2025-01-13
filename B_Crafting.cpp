#include<bits/stdc++.h> 
using namespace std ; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t ; 
	cin >> t ; 
	while(t--){
		int n ; cin >> n ;
		vector<int>arr1(n);
		for(auto & x : arr1){
			cin >> x ;
		}
		vector<int > min(n );
		for(auto & x : min){
			cin >> x ; 
		}
		int count = 0 ; 
		int minele = 0 ; 
		int count0 =0;
        int minpos = INT_MAX;
		for(int i = 0 ; i<n;i++){
			arr1[i]-=min[i];
			if(arr1[i]<0){
				count++;
				minele = arr1[i];
			}
            else{
                if(minpos<arr1[i]){
                    minpos = arr1[i];
                }
            }
			if(arr1[i]==0) count0++;

		}
		if(count > 1){
            cout<<"no"<<endl;
            continue;
        }
        if(count>0&&count0>0){
            cout<<"no"<<endl;
            continue;
        }

        if(minpos+minele<0){
            cout<<"no"<<endl;
            continue;

        }
        cout<<"yes"<<endl;
	}
	return 0 ; 
}