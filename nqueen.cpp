#include<bits/stdc++.h>
using namespace std;

bool isSafe(int board[10][10],int row,int col,int n){
	int x,y;
	for(int i=0;i<row;i++){
		if(board[i][col]==1){
			return false;
		}
	}
	x=row;
	y=col;
	while(x>=0&&y>=0){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y--;
	}

	x=row;
	y=col;
	while(x>=0&&y<n){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y++;
	}

	return true;
}

bool nqueen(int board[10][10],int row,int n){
	//base case
	if(row==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(board[i][j]==1){
					cout<<"Q ";
				}
				else{
					cout<<"_ ";
				}
			}
			cout<<endl;
		}
		return true;
	}
	//recursive case
	for(int j=0;j<n;j++){
		if(isSafe(board,row,j,n)){
			board[row][j]=1;
			bool temp=nqueen(board,row+1,n);
			if(temp){
				return true;
			}
		}
		board[row][j]=0;
	}
	return false;
}

int main(){
	int n;
	cin>>n;
	int board[10][10];
	bool res=nqueen(board,0,n);
	if(!res){
		cout<<"Not possible to place n queen"<<endl;
	}
}