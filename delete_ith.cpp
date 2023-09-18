#include<bits/stdc++.h>
using namespace std;

//delete element in ith position
int delete_ith_element(vector<int>& v,int i){
	int n=v.size();
	int key;
	if(i>v.size()){
		cout<<"wrong position"<<endl;
		return -1;
	}
	key=v[i];
	v[i]=v[n-1];
	v.pop_back();
	make_heap(v.begin(),v.end());
	return key;
}

int main(){
	vector<int> v={3,1,4,6,2,5};
	make_heap(v.begin(),v.end());
	//write your code here
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	int ans=delete_ith_element(v,3);
	for(auto x:v){
		cout<<x<<" ";
	}
	cout<<endl;
}