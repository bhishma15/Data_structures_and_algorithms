/*
find max area of rectanles in binary matrix;

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
	int n,m;
	cin>>n>>m;
	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	vector<int> v(m,0);
	for(int j=0;j<m;j++){
		v[j]=arr[0][j];
	}
	int mx=find_max_area(v);
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==0){
				v[j]=0;
			}else{
				v[j]+=arr[i][j];
			}
		}
		mx=max(mx,find_max_area(v));
	}
	cout<<"MAX AREA "<<mx<<endl;
}