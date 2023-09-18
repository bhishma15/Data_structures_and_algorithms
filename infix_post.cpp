#include<bits/stdc++.h>
using namespace std;

string solve(string str){
	stack<char> s;
	string n="";
	for(int i=0;i<str.length();i++){
		if(str[i]!='+'&&str[i]!='-'&&str[i]!='*'&&str[i]!='/'&&str[i]!='('&&str[i]!=')'){
			n+=str[i];
		}
		else if(str[i]==')'){
			while(s.top()!='('){
				n+=s.top();
				s.pop();
			}
			s.pop();
		}
		else{
			if(str[i]=='+'||str[i]=='-'){
				while(!s.empty()&&s.top()!='('){
					n+=s.top();
					s.pop();
				}
			}
			else if(str[i]=='*'||str[i]=='/'){
				while(!s.empty()&&(s.top()=='*'||s.top()=='/')&&s.top()!='('){
					n+=s.top();
					s.pop();
				}
			}
			s.push(str[i]);
		}
	}
	while(!s.empty()){
		n+=s.top();
		s.pop();
	}
	return n;
}

int main(){
	string str="A*B-(C+D)+E";
	string ans=solve(str);
	cout<<ans<<endl;
}