#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin>>tc;
	while(tc--){
	    string str;
	    cin>>str;
	    int l=0;
	    for(int i=0;i<str.length();i++){
	        if(str[i]=='.'){
	            reverse(str.begin()+l,str.begin()+i);
	            l=i+1;
	        }
	    }
	    reverse(str.begin()+l,str.end());
	    reverse(str.begin(),str.end());
	    cout<<str<<endl;
	}
	return 0;
}