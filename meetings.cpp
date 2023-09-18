/*
There is one meeting room in a firm. There are N meetings in the \
form of (S[i], F[i]) where S[i] is start time of meeting i and F[i]\
 is finish time of meeting i. What is the maximum number of meetings\
  that can be accommodated in the meeting room?
*/

#include<bits/stdc++.h>

using namespace std;
 
struct node{
	int s,e,id;
};

bool comp(node a , node b){
	if(a.e<=b.e)
		return true;
	return false;
}

void solve(vector<int> s,vector<int> e,int n){
	int vis[n];
	memset(vis,0,sizeof(vis));
	vector<node> v;
	for(int i=0;i<n;i++){
		node temp;
		temp.s=s[i];
		temp.e=e[i];
		temp.id=i+1;
		v.push_back(temp);
	}
	sort(v.begin(),v.end(),comp);
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			vis[i]=1;
			cout<<v[i].id<<" ";
			for(int j=i+1;j<n;j++){
				if(v[j].s<v[i].e){
					vis[j]=1;
				}
			}
		}
	}
	cout<<endl;
}
 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here
  int t;
  cin>>t;
  while(t--){
  	int n;
  	cin>>n;
  	vector<int> s(n,0),e(n,0);
  	for(int i=0;i<n;i++){
  		cin>>s[i];
  	}
  	for(int i=0;i<n;i++){
  		cin>>e[i];
  	}
  	solve(s,e,n);
  }
  

  return 0;
}