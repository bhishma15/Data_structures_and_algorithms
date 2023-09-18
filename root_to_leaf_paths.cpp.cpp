
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

int max_sum_level(Node *root){
	if(root==0){
		return 0;
	}
	int level=0.maxlevel=0;
	int current=0,max_sum=0;
	queue<Node *> q;
	q.push(root);
	q.push(0);
	while(!q.empty()){
		Node *t=q.front();
		q.pop();
		if(t==0){
			if(current>max_sum){
				max_sum=current;
				maxlevel=level;
			}
			current=0;
			level++;
			if(!q.empty()){
				q.push(0);
			}
		}
		else{
			current+=t->val;
			if(t->left){
				q.push(t->left);
			}
			if(t->right){
				q.push(t->right);
			}
		}
	}
	return maxlevel;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={1,2,3,4,5,6,7};
	Node *root;
	root=createList(v);
	//write your code here
	int ans=max_sum_level(root);
	cout<<"Sum is max at level "<<ans<<endl;
	return 0;
}