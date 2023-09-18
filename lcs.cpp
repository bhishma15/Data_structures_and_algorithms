/*
Given two strings X and Y. The task is to find the length of the \
longest common subsequence.
*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc;
	cin>>tc;
	while(tc--){
	    int n,m;
	    cin>>n>>m;
	    string x,y;
	    cin>>x>>y;
	    int arr[n+1][m+1];
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=m;j++){
	            arr[i][j]=0;
	        }
	    }
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=m;j++){
	            if(i==0||j==0){
	                arr[i][j]=0;
	            }else{
	                if(x[i-1]==y[j-1]){
	                    arr[i][j]=arr[i-1][j-1]+1;
	                }else{
	                	arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
	                }
	                
	            }
	        }
	    }
	    cout<<arr[n][m]<<endl;
	}
	return 0;
}