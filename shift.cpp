#include<bits/stdc++.h>
#include<sstream>

using namespace std;
 

int convert(string str){
	stringstream s;
	s<<str;
	int val;
	s>>val;
	return val;
}

string shift(string s){
	reverse(s.begin()+1,s.end());
	reverse(s.begin(),s.end());
	return s;
}

int find_max(string str){
	int mx=0;
	int n=str.length();
	while(n--){
		int num=convert(str);
		mx=max(mx,num);
		str=shift(str);
	}
	return mx;
}

int solve(){
	int n,k;
	cin>>n>>k;
	string str;
	cin>>str;
	int mx=find_max(str);
	int count=0,ans=0;
	while(count<k){
		int num=convert(str);
		if(num==mx){
			count++;
		}
		if(count!=k){
			ans++;
		}
		str=shift(str);
	}
	return ans;
}
 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here
  int tc;
  cin>>tc;
  while(tc--){
  	int ans=solve();
  	cout<<ans<<endl;
  }
  return 0;
}