#include<bits/stdc++.h>
#define N 7
using namespace std;

vector<int> adj[N];
int cnt[N];
//tree traversal using dfs
void traversal(int root,int prev){
	cout<<root<<" ";
	for(auto u:adj[root]){
		if(u!=prev)
		traversal(u,root);
	}
	return ;
}

//no of nodes in subtree
void subtree(int root,int prev){
	cnt[root]=1;
	for(auto u:adj[root]){
		if(u==prev) continue;
		subtree(u,root);
		cnt[root] += cnt[u];
	}
	return ;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//write your code here
	adj[0].push_back(1);
	adj[0].push_back(2);
	adj[1].push_back(3);
	adj[1].push_back(4);
	adj[2].push_back(5);
	adj[2].push_back(6);
	adj[3].push_back(1);
	adj[4].push_back(1);
	adj[5].push_back(2);
	adj[6].push_back(2);
	traversal(0,-1);
	cout<<endl;
	subtree(0,-1);
	for(int i=0;i<N;i++){
		cout<<cnt[i]<<" ";
	}
	cout<<endl;
	return 0;
}