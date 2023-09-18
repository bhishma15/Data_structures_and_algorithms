/*
Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (mat[][]). \
The task to print a solved Sudoku. For simplicity you may assume \
that there will be only one unique solution.

*/

#include<bits/stdc++.h>

using namespace std;
 
bool valid(int board[9][9],int x,int y,int k){
	for(int i=0;i<9;i++){
		if(board[x][i]==k){
			return false;
		}
	}
	for(int i=0;i<9;i++){
		if(board[i][y]==k){
			return false;
		}
	}
	int p,q;
	p=x/3;
	q=y/3;
	p=p*3;
	q=q*3;
	for(int i=p;i<p+3;i++){
		for(int j=q;j<q+3;j++){
			if(board[i][j]==k)
				return false;
		}
	}
	return true;
}

bool sudoku(int board[9][9],vector<pair<int,int> > v){
	if(v.size()==0){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return true;
	}
	pair<int,int> p=v.back();
	v.pop_back();
	int x,y;
	x=p.first;
	y=p.second;
	for(int k=1;k<=9;k++){
		if(valid(board,x,y,k)){
			board[x][y]=k;
			bool temp=sudoku(board,v);
			if(temp)
				return true;
			board[x][y]=0;
		}
	}
	return false;
}
 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here
  int t;
  cin>>t;
  while(t--){
  	int board[9][9];
  	vector<pair<int,int> > v;
  	for(int i=0;i<9;i++){
  		for(int j=0;j<9;j++){
  			cin>>board[i][j];
  			if(board[i][j]==0){
  				v.push_back({i,j});
  			}
  		}
  	}

  	cout<<endl<<endl;
  	sudoku(board,v);

  }
  return 0;
}