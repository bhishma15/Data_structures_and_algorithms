#include<bits/stdc++.h>
using namespace std;

//tree node structure
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
	Node(int val){
		this->val=val;
		this->left=0;
		this->right=0;
	}
};

//create complete tree
Node* createTree(vector<int> v){
	int n=v.size();
	if(n==0){
		return 0;
	}
	Node* root;
	Node* t[n];

	//create nodes of tree
	for(int i=0;i<n;i++){
		t[i]=new Node(v[i]);
	}

	for(int i=0;i<n;i++){
		int l=2*i+1;
		int r=2*i+2;
		if(l<n){
			t[i]->left=t[l];
		}
		if(r<n){
			t[i]->right=t[r];
		}
	}
	root=t[0];
	return root;
}

//recursive preorder traversal
void preorder(Node *root){
	if(root==0)
		return;
	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
	return;
}

//iterative preorder
void pre_iter(Node *root){
	stack<Node*> s;
	while(1){
		while(root){
			cout<<root->val<<" ";
			s.push(root);
			root=root->left;
		}
		if(s.empty()){
			break;
		}

		Node *t= s.top();
		s.pop();
		root=t->right;
	}
	return;
}
//recursive inorder traversal
void inorder(Node *root){
	if(root==0)
		return;
	
	preorder(root->left);
	cout<<root->val<<" ";
	preorder(root->right);
	return;
}

//iterative inorder
void in_iter(Node *root){
	stack<Node*> s;
	while(1){
		while(root){
			
			s.push(root);
			root=root->left;
		}
		if(s.empty()){
			break;
		}

		root= s.top();
		cout<<root->val<<" ";
		s.pop();
		root=root->right;
	}
	return;
}
//recursive preorder traversal
void postorder(Node *root){
	if(root==0)
		return;
	
	preorder(root->left);
	preorder(root->right);
	cout<<root->val<<" ";
	return;
}


//iterative postorder
void post_iter(Node *root){
	stack<Node*> s;
	Node *prev=0;
	do{
		while(root){
			s.push(root);
			root=root->left;
		}
		while(root==0 && !s.empty()){
			root=s.top();
			if(root->right==0||root->right==prev){
				cout<<root->val<<" ";
				s.pop();
				prev=root;
				root=0;
			}
			else{
				root=root->right;
			}
		}
	}while(!s.empty());
	return ;
}

//level order traversal
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
	//write your code here
	vector<int> v={1,2,3,4,5,6,7};
	Node *root;
	root=createTree(v);
	/*cout<<"preorder traversal"<<endl;
	preorder(root);
	cout<<endl;
	cout<<"inorder traversal"<<endl;
	inorder(root);
	cout<<endl;
	cout<<"postorder traversal"<<endl;
	postorder(root);
	cout<<endl;*/

	cout<<"preorder traversal"<<endl;
	pre_iter(root);
	cout<<endl;
	cout<<"inorder traversal"<<endl;
	in_iter(root);
	cout<<endl;
	cout<<"postorder traversal"<<endl;
	post_iter(root);
	cout<<endl;
	cout<<"level order traversal"<<endl;
	level_order(root);
	cout<<endl;
	return 0;
}