#include<bits/stdc++.h>

using namespace std;
 

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// A wrapper over leftViewUtil()
void leftView(Node *root){
    if(root==NULL)
    return ;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        int i=0;
        for(i=0;i<size;i++){
            Node *curr=q.front();
            q.pop();
            if(i==0){
                cout<<curr->data<<" ";
            }
            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
        }
    }
}
 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here

  return 0;
}