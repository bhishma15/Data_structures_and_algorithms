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


Node *find_lca(Node *root,Node *a,Node *b){
	if(root==0){
		return 0;
	}
	if(root==a||root==b){
		return root;
	}
	Node *left=find_lca(root->left,a,b);
	Node *right=find_lca(root->right,a,b);
	if(left&&right){
		return root;
	}
	else{
		return left?left:right;
	}

}

Node *fun(Node *root,int val){
	if(root==0){
		return 0;
	}
	if(root->val==val){
		return root;
	}

	Node *left,*right;
	left=fun(root->left,val);
	right=fun(root->right,val);
	return left?left:right;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={1,2,3,4,5,6,7};
	Node *root;
	root=createList(v);
	//write your code here
	Node *a=fun(root,4);
	Node *b=fun(root,7);
	Node *t=find_lca(root,a,b);
	cout<<t->val<<endl;
	return 0;
}