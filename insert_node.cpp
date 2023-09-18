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

void solve(Node *root,int val){

	Node *temp=new Node;
	if(temp==0){
		cout<<"Memory error"<<endl;
		return;
	}
	temp->val=val;
	if(root==0){
		root=temp;
		return;
	}
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		root=q.front();
		q.pop();
		if(root->left==0){
			root->left=temp;
			return;
		}
		else{
			q.push(root->left);
		}
		if(root->right==0){
			root->right=temp;
			return;
		}
		else{
			q.push(root->right);
		}
	}
}
void level_order(Node *root){
	queue<Node*> q;
	Node *t;
	if(root==0)
		return;
	q.push(root);
	while(!q.empty()){
		t=q.front();
		q.pop();
		cout<<t->val<<" ";
		if(t->left){
			q.push(t->left);
		}
		if(t->right){
			q.push(t->right);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={1,2,3,4,5,6,7};
	Node *root;
	root=createList(v);
	//write your code here
	solve(root,10);
	level_order(root);
	return 0;
}