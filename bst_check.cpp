#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int val;
	Node *left;
	Node *right;
	Node(){
		val=0;
		left=0;
		right=0;
	}
};

Node * createBST(Node *root,int val){
	Node *temp=new Node;
	
	if(!temp){
		cout<<"Memory Error"<<endl;
		return NULL;
	}
	temp->val=val;
	if(root==NULL){
		root=temp;
	}
	else{
		if(temp->val<(root)->val){
		root->left=createBST((root)->left,val);
		}
		else{
		root->right=createBST((root)->right,val);
		}
	}

	return root;
}

Node *find_min(Node *root){
	if(root==NULL){
		return NULL;
	}
	while(root->left != NULL){
		root=root->left;
	}
	return root;
}

Node *find_max(Node *root){
	if(root==NULL){
		return NULL;
	}
	while(root->right != NULL){
		root=root->right;
	}
	return root;
}

bool isBST(Node *root){
	if(root==0)
		return true;
	if(root->left&&find_max(root->left)->val>root->val)
		return false;
	if(root->right&&find_min(root->right)->val<root->val)
		return false;
	if(!isBST(root->left)||!isBST(root->right))
		return false;
	return true;
}

bool isBST_optimal(Node *root,int prev){
	if(!root)
		return true;
	if(!isBST_optimal(root->left,prev))
		return false;
	if(root->val < prev)
		return false;
	prev=root->val;
	return isBST_optimal(root->right,prev);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={1,3,4,2,6,5,7};
	Node *root=NULL;

	for(int i=0;i<7;i++){
		root=createBST(root,v[i]);
	}
	//write your code here
	bool ans=isBST(root);
	if(isBST_optimal(root,INT_MIN))
	{
		cout<<"BST"<<endl;
	}
	else{
		cout<<"Not BST"<<endl;
	}
	return 0;
}