#include<bits/stdc++.h>
#define F first
#define	S second
#define PB push_back
#define	MP make_pair
#define REP(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

//write your code here
void solve(int arr[],int n){
	for(int i=n;i>=1;i--){
		for(int j=0;j<i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
	return ;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//write your code here
	//solve();
	int arr[]={3,1,2,4,5};
	int n=5;

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	solve(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}