#include<bits/stdc++.h>

using namespace std;

bool ratInMaze(char maze[5][5],int solu[10][10],int i,int j,int m,int n){
	//base case
	if(i==m-1&&j==n-1){
		solu[i][j]=1;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cout<<solu[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}

	//recursive case
	if(i>=m || j>=n){
		return false;
	}
	if(maze[i][j]=='X'){
		return false;
	}
	solu[i][j]=1;
	bool right=ratInMaze(maze,solu,i,j+1,m,n);
	bool down=ratInMaze(maze,solu,i+1,j,m,n);

	if(right||down){
		return true;
	}
		solu[i][j]=0;
	return false;
}

int main(){
	int m=4,n=4;
	int solu[10][10]={0};
	char maze[5][5]={
		"0000",
		"00X0",
		"000X",
		"0X00"
	};
	bool ans=ratInMaze(maze,solu,0,0,m,n);
	if(ans==false){
		cout<<"Not possible any path"<<endl;
	}
	return 0;
}