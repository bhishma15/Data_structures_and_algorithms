/*
Bottem view of binary tree

*/

#include<bits/stdc++.h>

using namespace std;
 

vector <int> bottomView(Node *root)
{
   // Your Code Here
   queue<Node*> p;
   queue<int>q;
   map<int,int> mp;
   vector<int> v;
   if(root==0)
   return v;
   
   p.push(root);
   q.push(0);
   while(!p.empty()){
       Node *temp=p.front();
       int hd=q.front();
       mp[hd]=temp->data;
       p.pop();
       q.pop();
       if(temp->left){
           p.push(temp->left);
           q.push(hd-1);
       }
       if(temp->right){
           p.push(temp->right);
           q.push(hd+1);
       }
   }
   for(auto x:mp){
       v.push_back(x.second);
   }
   return v;
}
 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here

  return 0;
}