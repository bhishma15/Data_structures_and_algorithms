/*
The n-queens puzzle is the problem of placing n queens\
 on an n×n chessboard such that no two queens attack each \
 other. Given an integer n, print all distinct \
  to the n-queens puzzle.
*/

#include<bits/stdc++.h>
using namespace std;
bool isSafe(int board[100][100],int i,int j,int n){
    int x,y;
    x=i;
    y=j;
    while(x>=0&&y>=0){
        if(board[x][y])
        {
            return false;
        }
        x--;
        y--;
    }
    x=i;
    y=j;
    while(x>=0){
        if(board[x][y])
        {
            return false;
        }
        x--;
    }
    x=i;
    y=j;
    while(x>=0&&y<n){
        if(board[x][y])
        {
            return false;
        }
        x--;
        y++;
    }
    return true;
}

bool nqueens(int board[100][100],int i,int n){
    if(i==n){
        vector<int> v;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //cout<<board[i][j]<<" ";
                if(board[i][j]){
                    v.push_back(j+1);
                    break;
                }
            }
        }
        cout<<"[";
        for(int k=0;k<v.size();k++){
            cout<<v[k]<<" ";
        }
        cout<<" ]"<<endl;
        return false;
    }
    
    for(int j=0;j<n;j++){
        if(isSafe(board,i,j,n)){
            board[i][j]=1;
            bool temp=nqueens(board,i+1,n);
            if(temp){
                return true;
            }
            board[i][j]=0;
        }
    }
    return false;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int board[100][100]={0};
	    nqueens(board,0,n);
	}
	return 0;
}