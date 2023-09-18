/*
Given n non-negative integers representing the histogram's \
bar height where the width of each bar is 1, find the area of\
 largest rectangle in the histogram.

*/

#include<bits/stdc++.h>
using namespace std;

  int  find_max_area(vector<int> v){
  	v.insert(v.begin(),INT_MIN);
  	v.push_back(INT_MIN);
  	int n=v.size();
	int nsl[n],nsr[n];
	stack<pair<int,int> > s;
	for(int i=0;i<n;i++){
		if(s.empty()){
			nsl[i]=-1;
		}else{
			while(!s.empty()&&s.top().first>=v[i]){
				s.pop();
			}
			if(s.empty()){
				nsl[i]=-1;
			}else{
				nsl[i]=s.top().second;
			}
		}
		s.push({v[i],i});
	}
	while(!s.empty()){
		s.pop();
	}
	for(int i=n-1;i>=0;i--){
		if(s.empty()){
			nsr[i]=-1;
		}else{
			while(!s.empty()&&s.top().first>=v[i]){
				s.pop();
			}
			if(s.empty()){
				nsr[i]=-1;
			}else{
				nsr[i]=s.top().second;
			}
		}
		s.push({v[i],i});
	}
	int w,h,area=-1;
	for(int i=1;i<n-1;i++){
        w=nsr[i]-nsl[i]-1;
		h=v[i];
		int temp=w*h;
		area=max(area,temp);
	}
	return area;
}

int main(){
	vector<int> arr={6,2,5,4,5,1,6};
	int n=arr.size();
	int ans=find_max_area(arr);
	cout<<"MAX AREA "<<ans<<endl;
}