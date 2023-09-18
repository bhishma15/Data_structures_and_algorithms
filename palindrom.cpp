/*
Given a string S, find the longest palindromic substring in S. \
Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). \
Palindrome string: A string which reads the same backwards. \
More formally, S is palindrome if reverse(S) = S. \
Incase of conflict, return the substring which occurs first \
( with the least starting index ).
*/
#include <bits/stdc++.h>
using namespace std;


int main() {
	//code
	int tc;
	cin>>tc;
	while(tc--){
	    string str;
	    cin>>str;
	    int n=str.length();
	    if(n<3){
	        if(n==1){
	            cout<<str<<endl;
	        }else{
	            if(str[0]==str[1]){
	                cout<<str<<endl;
	            }else{
	                cout<<str[0]<<endl;
	            }
	        }
	    }else{
	    vector<int> arr[n];
	    for(int i=0;i<n;i++){
	        vector<int> v(n,0);
	        arr[i]=v;
	    }
	    
	    for(int i=0;i<n;i++){
	        arr[i][i]=1;
	    }
	    
	    for(int i=0;i<n-1;i++){
	        if(str[i]==str[i+1])
	        arr[i][i+1]=2;
	    }
	    int size=n-2;
	    for(int len=3;len<=n;len++){
	        int low=0,high=len-1;
	        for(int i=0;i<size;i++){
	            if(str[low]==str[high]&&arr[low+1][high-1]!=0){
	                arr[low][high]=arr[low+1][high-1]+2;
	            }
	            low++;
	            high++;
	        }
	        size--;
	    }
	    /*int x,y,mx=0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(i>j)continue;
	            if(arr[i][j]>mx){
	                mx=arr[i][j];
	                x=i;
	                y=j;
	            }
	        }
	    }
	    cout<<str.substr(x,y)<<endl;
	    }*/
	    int mx=0,x,y;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(arr[i][j]>mx){
	                mx=arr[i][j];
	                x=i,y=j;
	            }
	        }
	        //cout<<endl;
	    }
	    //cout<<mx<<" "<<x<<" "<<y<<endl;
	    for(int i=x;i<=y;i++){
	        cout<<str[i];
	    }
	    cout<<endl;
	    }
	}
	return 0;
}