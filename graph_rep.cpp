#include<bits/stdc++.h>
#define N 100
using namespace std;

void solve(){
	//list reresentation for unweighted graph 
	vector<int> adj[N];
	adj[1].push_back(2);
	adj[2].push_back(3);
	adj[2].push_back(4);
	adj[3].push_back(4);
	adj[4].push_back(1);

	for(auto u:adj[2]){
		cout<<u<<" ";
	}
	cout<<endl;
	cout<<endl;
	//list reresentation for weighted graph
	//adj[a].push_back(b,w);
	//w is weigth of edge a->b
	vector<pair<int,int > > adj_list[N];
	adj_list[1].push_back({2,5});
	adj_list[2].push_back({3,7});
	adj_list[2].push_back({4,6});
	adj_list[3].push_back({4,5});
	adj_list[4].push_back({1,2});

	for(auto u:adj_list[2]){
		cout<<u.first<<" "<<u.second<<endl;
	}
	cout<<endl;
	//matrix representation
	int adj_mat[N][N];
	memset(adj_mat,0,sizeof(adj_mat));
	adj_mat[1][2]=5;
	adj_mat[2][3]=7;
	adj_mat[2][4]=6;
	adj_mat[3][4]=5;
	adj_mat[4][1]=2;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			cout<<adj_mat[i][j]<<" ";
		}
		cout<<endl;
	}

	//edge list representation of weighted graph
	//edge from a->b (a,b)
	vector<pair<int,int> > edges;
	edges.push_back({1,2})
	//edge list representation of weighted graph
	//edge from a->b with weight w (a,b,w)
	vector<tuple<int,int,int>> edge_list;
	edge_list.push_back({1,2,5});

	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//write your code here
	solve();
	return 0;
}