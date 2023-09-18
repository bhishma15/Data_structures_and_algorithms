#include<bits/stdc++.h>
using namespace std;


int main(){
	
	vector<int> adj[26];
	int n,k;
	cin>>n>>k;
	bool pres[26];
	int deg[26]={0};
	vector<string> dict(n);
	for(int i=0;i<n;i++){
		cin>>dict[i];
	}
	bool vis[26];
	for(int i=0;i<26;i++){
		vis[i]=false;
		pres[i]=false;
	}
	for(int i=0;i<n-1;i++){
		string a,b;
		a=dict[i];
		b=dict[i+1];
		int k=0;
		while(k<a.length()&&k<b.length()){
			if(a[k]!=b[k]){
				adj[a[k]-'a'].push_back(b[k]-'a');
				pres[a[k]-'a']=true;
				pres[b[k]-'a']=true;
				deg[b[k]-'a']++;
				break;
			}
			k++;
		}
	}
	
	stack<int> stk;
	for(int i=0;i<26;i++){
		if(pres[i]&&deg[i]==0){
			dfs(adj,i,vis,stk);
			break;
		}
	}
	while(!stk.empty()){
		char ch=stk.top()+'a';
		cout<<ch<<" ";
		stk.pop();
	}
	cout<<endl;
}