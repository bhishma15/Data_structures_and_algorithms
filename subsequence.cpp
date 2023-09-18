#include<bits/stdc++.h>
using namespace std;

void subseq(char *in,char *out,int i,int j){
	//BASE CONDITION
	if(in[i]=='\0'){
		out[j]='\0';
		cout<<out<<" , ";
		return;
	}

	//RECURSIVE CALL
	out[j]=in[i];
	subseq(in,out,i+1,j+1);

	subseq(in,out,i+1,j);
}

int main(){
	char in[100],out[100];
	cin>>in;
	int i=0,j=0;
	subseq(in,out,i,j);	
	return 0;
} 