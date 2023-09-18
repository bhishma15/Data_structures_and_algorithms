#include<bits/stdc++.h>
using namespace std;

//it evaluate postfix operation

int solve(string str){
	stack<int> s;
	for(int i=0;i<str.length();i++){
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
			int a,b;
			a=s.top();
			s.pop();
			b=s.top();
			s.pop();
			switch(str[i]){
				case '+':{
					s.push(a+b);
					break;
				}
				case '-':{
					s.push(abs(a-b));
					break;
				}
				case '*':{
					s.push(a*b);
					break;
				}
				case '/':{
					s.push(a/b);
					break;
				}
			}
			
		}else{
			s.push(str[i]-'0');
		}
	}
	return s.top();
}

int main(){
	string str="34+42-*";
	int ans=solve(str);
	cout<<ans<<endl;
}