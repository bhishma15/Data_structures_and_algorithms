/*
Given a string S. The task is to print all permutations of a given string.
*/

#include <bits/stdc++.h>
using namespace std;



void permute(string s,int i,vector<string>& v){
    int n=s.length();
    if(i==n){
        //cout<<s<<endl;
        v.push_back(s);
        return;
    }else{
        for(int j=i;j<n;j++){
            swap(s[i],s[j]);
            permute(s,i+1,v);
            swap(s[i],s[j]);
        }
    }
    return;
}
int main() {
	//code
	int tc;
	cin>>tc;
	while(tc--){
	    string str;
	    cin>>str;
	    vector<string> v;
	    int n=str.length();
	    permute(str,0,v);
	    sort(v.begin(),v.end());
	    for(int i=0;i<v.size();i++){
	        cout<<v[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}