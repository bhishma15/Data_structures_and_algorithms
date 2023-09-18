#include<bits/stdc++.h>
#define N 4
using namespace std;


//union-find structure
int link[N];
int size[N];

int find(int x){
	while(x!=link[x]) x=link[x];
	return x;
}

bool same(int a,int b){
	return find(a)==find(b);
}

void unite(int a,int b){
	 a=find(a);
	 b=find(b);
	 if(size[a]<size[b]) swap(a,b);
	 size[a]+=size[b];
	 link[b]=a;
	 return;
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//write your code here
	for(int i=0;i<N;i++){
		link[i]=i;
		size[i]=1;
	}


	return 0;
}