/*
Given N activities with their start and finish times. \
Select the maximum number of activities that can be \
performed by a single person, assuming that a person \
can only work on a single activity at a time.
*/

#include<bits/stdc++.h>

using namespace std;



int solve(int n){
    int s[n],f[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++){
        v.push_back({f[i],s[i]});
    }
    sort(v.begin(),v.end());
    bool vis[n];
    for(int i=0;i<n;i++){
        vis[i]=false;
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i]=true;
            count++;
            for(int j=i+1;j<n;j++){
                if(v[j].second<v[i].first){
                    vis[j]=true;
                }
            }
        }
    }
    return count;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int res=solve(n);
	    cout<<res<<endl;
	}
	return 0;
}