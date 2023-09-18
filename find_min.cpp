#include<bits/stdc++.h>
using namespace std;

//find minimum in max heap
int find_min(vector<int> v){
	int mx=INT_MAX;
	int t=(v.size()-1)/2;
	t++;
	for(int i=t;i<v.size();i++){
		mx=min(mx,v[i]);
	}
	return mx;
}

int main(){
	vector<int> v={3,1,4,6,2,5};
	make_heap(v.begin(),v.end());
	//write your code here
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	int ans=find_min(v);
	cout<<ans<<endl;
}