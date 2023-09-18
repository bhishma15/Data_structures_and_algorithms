/*
Given an integer an N. The task is to print the position of \
first set bit found from right side in the binary representation \
of the number.
*/
#include<iostream>
using namespace std;
int solve(int n){
    for(int i=0;i<64;i++){
        if(n&(1<<i)){
            return i+1;
        }
    }
    return 0;
}
int main()
 {
	//
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int ans=solve(n);
	    cout<<ans<<endl;
	}
	return 0;
}