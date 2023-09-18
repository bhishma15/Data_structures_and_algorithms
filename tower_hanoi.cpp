#include<bits/stdc++.h>
using namespace std;

void tower(int n,char src,char dest,char help){
	//BASE CONDITION
	if(n==0)
		return;

	//RECURSIVE CALL
	tower(n-1,src,help,dest);
	cout<<"move "<<n<<" disk from "<<src<<" to "<<dest<<endl;
	tower(n-1,help,dest,src);
}

int main(){
	int n;
	cin>>n;
	tower(n,'A','C','B');

	return 0;
} 