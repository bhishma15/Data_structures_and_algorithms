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

bool identical(Node *root1,Node *root2){
	if(root1==0&&root2==0){
		return true;
	}

	if(root1==0||root2==0){
		return false;
	}

	return (root1->val==root2->val&&identical(root1>left,root2->left)&&identical(root1->right,root2->right));
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={1,2,3,4,5,6,7};
	Node *root;
	root=createList(v);
	//write your code here
	bool ans=identical(root,root);
	if(ans){
		cout<<"Structurally identical"<<endl;
	}
	else{
		cout<<"Not Identical"<<endl;
	}
	
	return 0;
}