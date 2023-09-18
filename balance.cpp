#include<bits/stdc++.h>
using namespace std;

//check balance of paranthesis
bool isbalance(string str){
stack<char> s;
for(int i=0;i<str.length();i++){
	if(str[i]=='('||str[i]=='{'||str[i]=='['){
		s.push(str[i]);
	}
	else if(str[i]==')'||str[i]=='}'||str[i]==']'){
		if(s.empty()){
			return false;
		}
		else{
			char ch=s.top();
			if((ch=='('&&str[i]==')')||(ch=='['&&str[i]==']')||(ch=='{'&&str[i]=='}')){
				s.pop();
			}
			else{
				return false;
				
			}
		}
	}
}
	if(!s.empty())
		return false;
	return true;
}

int main(){
	string s="(()})";
	if(isbalance(s)){
		cout<<s<<" is balanced"<<endl;
	}
	else{
		cout<<s<<" is not balanced"<<endl;
	}
}