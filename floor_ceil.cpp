/*
find the floor and ceil element in sorterd array
*/


#include<bits/stdc++.h>

using namespace std;
 

int floor(vector<int> v,int x){
	int start=0;
	int end=v.size()-1;
	int res=-1;
	while(start<=end){
		int mid=start+(end-start)/2;
		if(x==v[mid]){
			return v[mid];
		}else if(x<v[mid]){
			end=mid-1;
		}else{
			res=v[mid];
			start=mid+1;
		}
	}
	return res;
}
 
 int ceil(vector<int> v,int x){
	int start=0;
	int end=v.size()-1;
	int res=-1;
	while(start<=end){
		int mid=start+(end-start)/2;
		if(x==v[mid]){
			return v[mid];
		}else if(x<v[mid]){
			res=v[mid];
			end=mid-1;
		}else{
			//res=v[mid];
			start=mid+1;
		}
	}
	return res;
}
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here
  vector<int> v={1,2,3,5,6,8};
  int res=ceil(v,4);
  cout<<res<<endl;
  return 0;
}