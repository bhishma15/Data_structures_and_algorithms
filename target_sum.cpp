#include<bits/stdc++.h>

using namespace std;
 

bool solve(int a[],int b[],int n,int k){
	sort(a,a+n);
	for(int i=0;i<n;i++){
		int c=k-b[i];
		if(binary_search(a,a+n,c)){
			return true;
		}
	}
	return false;
}
 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here
 int n,k;
 cin>>n>>k;
 int a[n],b[n];
 for(int i=0;i<n;i++){
 	cin>>a[i];
 }
 for(int i=0;i<n;i++){
 	cin>>b[i];
 }
 if(solve(a,b,n,k)){
 	cout<<"present"<<endl;
 }else{
 	cout<<"not present"<<endl;
 }
  return 0;
}