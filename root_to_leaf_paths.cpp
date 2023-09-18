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

void print_array(int arr[],int len){
	for(int i=0;i<len;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return;
}

void print_path(Node *root,int path[],int len){
	if(root==0)
		return;
	path[len]=root->val;
	len++;
	if(root->left==0&&root->right==0)
		print_array(path,len);
	else{
		print_path(root->left,path,len);
		print_path(root->right,path,len);
	}
	return ;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={1,2,3,4,5,6,7};
	Node *root;
	root=createList(v);
	//write your code here
	int len=0;
	int path[100];
	print_path(root,path,0);
	
	return 0;
}