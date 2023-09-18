/*
find the first subarray whose total sum is equal to given sum
*/
#include<iostream>
using namespace std;
int main()
 {
	//code
	int tc;
	cin>>tc;
	while(tc--){
	    int n,sum;
	    cin>>n>>sum;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int start=0,end=0,temp=0;
	    bool flg=true;
	    while(end<=n){
	        if(temp==sum){
	            flg=false;
	            cout<<start+1<<" "<<end<<endl;
	            break;
	        }else if(temp<sum){
	            temp+=arr[end++];
	        }else if(temp>sum){
	            while(temp>sum&&start<end){
	                temp-=arr[start++];
	            }
	        }
	    }
	    if(flg)
	    cout<<-1<<endl;
	   
	}
	return 0;
}