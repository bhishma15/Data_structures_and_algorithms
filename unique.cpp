/*
Given a sorted array A, size N, of integers; every element \
appears twice except for one. Find that element that appears\
 once in array.

*/

#include<iostream>
#define ll long long int
using namespace std;
ll solve(ll arr[],ll n){
    ll s,e;
    s=0;
    e=n-1;
    while(s<=e){
        if(s==e){
            return arr[s];
        }
        ll d=(e-s)/2;
        ll m=s+d;
        if(m==0||m==n-1){
            return arr[m];
        }else if(arr[m-1]==arr[m]){
                if(d%2==0){
                    e=m-2;
                }else{
                    s=m+1;
                }
        }else if(arr[m+1]==arr[m]){
            if(d%2==0){
                    s=m+2;
                }else{
                    e=m-1;
                }
        }else{
            return arr[m];
        }
    }
    return 0;
}
int main()
 {
	//code
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    ll arr[n];
	    for(ll i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    ll ans=solve(arr,n);
	    cout<<ans<<endl;
	}
	return 0;
}