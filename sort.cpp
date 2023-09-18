/*
Given an array A[] of integers, sort the array according to \
frequency of elements. That is elements that have higher \
frequency come first. If frequencies of two elements are same, \
then smaller number comes first.
*/

#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int,int> x,pair<int,int> y){
    if(x.first>y.first){
        return true;
    }
    if(x.first==y.first){
        if(x.second<y.second){
            return true;
        }
    }
    return false;
}

int main() {
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        map< int,int > mp; 
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            mp[x]++;
        }
        vector< pair<int,int> > v;
        for(int i=0;i<61;i++){
            if(mp.find(i)!=mp.end())
            v.push_back({mp[i],i});
        }
        sort(v.begin(),v.end(),comp);
        for(auto x:v){
            int count=x.first;
            while(count--){
                cout<<x.second<<" ";
            }
        }
        cout<<endl;
    }
}