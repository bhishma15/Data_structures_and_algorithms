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

Node *find_lca(Node *root,Node *a,Node *b){
	while(1){
		if((a->val<root->val&&b->val>root->val)||(a->val>root->val&&b->val<root->val)){
			return root;
		}
		if(a->val<root->val){
			root=root->left;
		}
		else{
			root=root->right;
		}
	}
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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={1,3,4,2,6,5,7};
	Node *root=NULL;

	for(int i=0;i<7;i++){
		root=createBST(root,v[i]);
	}
	//write your code here
	Node *a=find(root,2);
	Node *b=find(root,7);
	Node *t=find_lca(root,a,b);
	cout<<"Lca of "<<a->val<<" and "<<b->val<<" is "<<t->val<<endl;
	return 0;
}