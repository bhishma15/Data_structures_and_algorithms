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

void traverse(Node *root){
	if(root==0){
		return;
	}
	cout<<root->val<<" ";
	traverse(root->left);
	traverse(root->right);
	return;
}

Node *find(Node *root,int val){
	if(root==NULL){
		return NULL;
	}
	if(root->val > val){
		return find(root->left,val);
	}
	else if(val>root->val){
		return find(root->right,val);
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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={1,3,4,2,6,5,7};
	Node *root=NULL;

	for(int i=0;i<7;i++){
		root=createBST(root,v[i]);
	}
	//write your code here
	Node *t;
	t=find_max(root);
	cout<<t->val<<endl;
	return 0;
}