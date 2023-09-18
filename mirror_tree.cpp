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

Node* createList(vector<int> v){
	int n=v.size();
	if(n==0){
		return 0;
	}
	Node* root;
	Node* t[n];
	for(int i=0;i<n;i++){
		t[i]=new Node;
	}
	for(int i=0;i<n;i++){
		t[i]->val=v[i];
	}

	for(int i=1;i<n;i++){
		if(i&1){
			int ind=i/2;
			t[ind]->left=t[i];
		}
		else{
			int ind=(i/2)-1;
			t[ind]->right=t[i];
		}
	}
	root=t[0];
	return root;
}

void mirror_tree(Node *root){
	if(root==0){
		return ;
	}
	mirror_tree(root->left);
	mirror_tree(root->right);
	Node *t;
	t=root->left;
	root->left=root->right;
	root->right=t;
	return ;
}

void traverse(Node *root){
	if(root==0){
		return ;
	}
	cout<<root->val<<" ";
	traverse(root->left);
	traverse(root->right);
	return;
}

bool check_mirror(Node *root1,Node *root2){
	if(!root1&&!root2){
		return true;
	}
	if(!root1||!root2){
		return false;
	}
	if(root1->val!=root2->val){
		return false;
	}
	else{
		return check_mirror(root1->left,root2->right)&&check_mirror(root1->right,root2->left);
		 }
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={1,2,3,4,5,6,7};
	Node *root;
	root=createList(v);
	//write your code here
	/*traverse(root);
	cout<<endl;
	mirror_tree(root);
	traverse(root);
	cout<<endl;*/

	bool ans=check_mirror(root,root);
	if(ans){
		cout<<"Mirror trees"<<endl;
	}
	else{
		cout<<"Not Mirror trees"<<endl;
	}

	return 0;
}