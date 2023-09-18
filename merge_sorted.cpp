#include<bits/stdc++.h>
#define  vi vector<int>
#define  pb push_back
using namespace std;
 

//merge using heap

vi merge(vi adj[],int k){
 	/*for(int i=0;i<k;i++){
 		reverse(adj[i].begin(),adj[i].end());
 	}*/
 	priority_queue<pair<int,int> > q;
 	for(int i=0;i<k;i++){
 		q.push({adj[i].back(),i});
 		adj[i].pop_back();
 	}
 	vector<int> res;
 	while(!q.empty()){
 		int val,ind;
 		pair<int,int> x=q.top();
 		q.pop();
 		val=x.first;
 		ind=x.second;
 		res.push_back(val);
 		if(adj[ind].size()!=0){
 			q.push({adj[ind].back(),ind});
 			adj[ind].pop_back();
 		}
 	}
 	return res;
 }

//merge each list one by one o(nk)
vi solve(vi adj[],int k){
	vi res;
	res=adj[0];
	for(int i=1;i<k;i++){
		vi temp;
		int a,b;
		a=0,b=0;
		while(a<res.size()&&b<adj[i].size()){
			if(res[a]<adj[i][b]){
				temp.pb(res[a++]);
			}else{
				temp.pb(adj[i][b++]);
			}
		}
		while(a<res.size()){
			temp.pb(res[a++]);
		}
		while(b<adj[i].size()){
			temp.pb(adj[i][b++]);
		}
		res=temp;
	}
	return res;
}
 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here
  int k;
  cin>>k;
  vi adj[k];
  for(int i=0;i<k;i++){
  	int n;
  	vi v;
  	cin>>n;
  	for(int j=0;j<n;j++){
  		int t;
  		cin>>t;
  		v.pb(t);
  	}
  	adj[i]=v;
  }
  vi res;
  res=merge(adj,k);
  cout<<endl;
  for(int i=0;i<res.size();i++){
  	cout<<res[i]<<" ";
  }
  cout<<endl;
  return 0;
}