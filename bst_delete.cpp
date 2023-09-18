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



Node *find_max(Node *root){
	if(root==NULL){
		return NULL;
	}
	while(root->right != NULL){
		root=root->right;
	}
	return root;
}

Node * bst_delete(Node *root,int val){
	if(root==0){
		cout<<"Element is not present"<<endl;
	}
	else if(val<root->val){
		root->left=bst_delete(root->left,val);
	}
	else if(val>root->val){
		root->right=bst_delete(root->right,val);
	}
	else{
		if(root->left&&root->right){
			Node *t=find_max(root->left);
			root->val=t->val;
			root->left=bst_delete(root->left,t->val);
		}
		else{
			Node* temp=root;
			if(root->left==0){
				root=root->right;
			}
			if(root->right==0){
				root=root->left;
			}
			delete(temp);
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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={5,4,1,3,6,7,2};
	Node *root=NULL;

	for(int i=0;i<7;i++){
		root=createBST(root,v[i]);
	}
	//write your code here
	traverse(root);
	cout<<endl;
	bst_delete(root,5);
	traverse(root);
	cout<<endl;
	return 0;
}