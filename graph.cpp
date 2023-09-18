#include<bits/stdc++.h>
using namespace std;

//matrix representation
vector<vector<int> > graphCreateMat(){
	int n;
	cout<<"Enter no of vertices"<<endl;
	cin>>n;
	vector<vector<int> > v;
	for(int i=0;i<n;i++){
		vector<int> x(n,0);
		v.push_back(x);
	}
	int m;
	cout<<"Enter no of edges"<<endl;
	cin>>m;
	while(m--){
		int x,y;
		cin>>x>>y;
		v[x-1][y-1]=1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	return v;
}

//adjacency list for weighted graph
vector<pair<int,int>> createListGraph(){
	int n;
	cout<<"Enter no of nodes"<<endl;
	cin>>n;
	vector<pair<int,int> > adj[n];
	int m;
	cout<<"enter edges"<<endl;
	cin>>m;
	while(m--){
		int x,y,w;
		cin>>x>>y>>w;
		adj[x].push_back({y,w});
	}
  return adj[n];
}

//adjacency list for non-weighted graph

vector<int> createList(){
		int n;
	cout<<"Enter no of nodes"<<endl;
	cin>>n;
	vector<int> adj[n];
	int m;
	cout<<"enter edges"<<endl;
	cin>>m;
	while(m--){
		int x,y;
		cin>>x>>y>>w;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
  return adj[n];
}
int main(){
	vector<vector<int> > g;
	g=graphCreateMat();
	
}