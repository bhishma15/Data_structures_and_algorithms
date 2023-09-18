#include<bits/stdc++.h>

using namespace std;
 

bool checkBST(Node *root,int min,int max){
    if(root==0)
    return true;
    if(root->data<min||root->data>max){
        return false;
    }
    
    return checkBST(root->left,min,root->data-1)&&checkBST(root->right,root->data-1,max);
}

int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here

  return 0;
}