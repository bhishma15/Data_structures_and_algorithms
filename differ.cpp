/*
Given two numbers M and N. The task is to find the position of \
rightmost different bit in binary representation of numbers.
*/

#include<iostream>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int m,n;
	    cin>>m>>n;
	    if(m==n){
	        cout<<-1<<endl;
	    }else{
	         for(int i=0;i<32;i++){
	        int x,y;
	        if(m&(1<<i)){
	            x=1;
	        }else{
	            x=0;
	        }
	        if(n&(1<<i)){
	            y=1;
	        }else{
	            y=0;
	        }
	        if(x!=y){
	            cout<<i+1<<endl;
	            break;
	        }
	    }
	    }
	   
	}
	return 0;
}