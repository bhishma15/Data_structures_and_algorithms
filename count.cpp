/*
find the fcount of an element  in sorterd array
*/


#include<bits/stdc++.h>

using namespace std;
 

int search_1st_occur(vector<int> v,int x){
	int start=0;
	int end=v.size()-1;
	int res=-1;
	while(start<=end){
		int mid=start+(end-start)/2;
		if(x==v[mid]){
			res=mid;
			end=mid-1;
		}else if(x<v[mid]){
			end=mid-1;
		}else{
			start=mid+1;
		}
	}
	return res;
}
 
int search_last_occur(vector<int> v,int x){
	int start=0;
	int end=v.size()-1;
	int res=-1;
	while(start<=end){
		int mid=start+(end-start)/2;
		if(x==v[mid]){
			res=mid;
			start=mid+1;
		}else if(x<v[mid]){
			end=mid-1;
		}else{
			start=mid+1;
		}
	}
	return res;
}

int count(vector<int> v,int x){
	int first=search_1st_occur(v,x);
	int last=search_last_occur(v,x);
	if(first==-1){
		return 0;
	}
	int res=last-first+1;
	return res;
}

int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here
  vector<int> v={1,2,3,3,3,3,3,4,5,6};
  int res=count(v,3);
  cout<<res<<endl;
  return 0;
}