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

int find_size(Node *root){
	if(root==0){
		return 0;
	}
	return 1+find_size(root->left)+find_size(root->right);
}

//iterartive

int find_s(Node *root){
	int count=0;
	if(root==0){
		return 0;
	}
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		root=q.front();
		q.pop();
		count++;
		if(root->left){
			q.push(root->left);
		}
		if(root->right){
			q.push(root->right);
		}
	}
	return count;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={1,2,3,4,5,6,7};
	Node *root;
	root=createList(v);
	//write your code here
	int res=find_s(root);
	cout<<"size of the tree = "<<res<<endl;

	return 0;
}