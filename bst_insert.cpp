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

Node * insert_bst(Node *root,int val){

	
	
	
	if(root==NULL){
			Node *temp=new Node;
			temp->val=val;
		root=temp;
	}
	else{
		if(val<(root)->val){
		root->left=insert_bst((root)->left,val);
		}
		else{
		root->right=insert_bst((root)->right,val);
		}
	}

	return root;
}





int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={1,3,4,2,6,5,7};
	Node *root=NULL;

	
	//write your code here
	for(int i=0;i<7;i++){
		root=insert_bst(root,v[i]);
	}
	return 0;
}