/*
Given a 2D screen, location of a pixel in the screen ie(x,y) and \
a color(K), your task is to replace color of the given pixel and \
all adjacent(excluding diagonally adjacent) same colored pixels \
with the given color K.

*/

#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<int> >& v,int x,int y,int val,int k,int n,int m){
    if(x<0||y<0||x>=n||y>=m)
    return;
    if(v[x][y]==val){
        v[x][y]=k;
        solve(v,x-1,y,val,k,n,m);
        solve(v,x+1,y,val,k,n,m);
        solve(v,x,y-1,val,k,n,m);
        solve(v,x,y+1,val,k,n,m);
    }
    return;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int> > v(n,vector<int> (m,0) );
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cin>>v[i][j];
	        }
	    }
	    int x,y,k;
	    cin>>x>>y>>k;
	    solve(v,x,y,v[x][y],k,n,m);
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cout<<v[i][j]<<" ";
	        }
	        //cout<<endl;
	    }
	    cout<<endl;
	}
	return 0;
}