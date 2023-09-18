/*
find the element index in sorterd array
*/


#include<bits/stdc++.h>

using namespace std;
 

int search(vector<int> v,int x){
	int start=0;
	int end=v.size()-1;
	while(start<=end){
		int mid=start+(end-start)/2;
		if(x==v[mid]){
			return mid;
		}else if(x<v[mid]){
			end=mid-1;
		}else{
			start=mid+1;
		}
	}
	return -1;
}
 
 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here
  vector<int> v={1,2,3,4,5,6};
  int res=search(v,8);
  cout<<res<<endl;
  return 0;
}