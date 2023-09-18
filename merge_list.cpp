#include<bits/stdc++.h>

using namespace std;

class node{
public:
	int data;
	node *next;
	node(int data){
		this->data=data;
		this->next=0;
	}
};

node* create_list(vector<int> v){
	node *head=0;
	if(v.size()==0)
		return head;
	node *t=new node(v[0]);
	head=t;
	for(int i=1;i<v.size();i++){
		node *temp=new node(v[i]);
		t->next=temp;
		t=t->next;
	}
	return head;
}

//merge sorted list using recursion
node* merge_list(node *head1,node *head2){
	node *result=0;
	if(head1==0)
		return head2;
	if(head2==0)
		return head1;
	if(head1->data<=head2->data){
		result=head1;
		result->next=merge_list(head1->next,head2);
	}
	else{
		result=head2;
		result->next=merge_list(head1,head2->next);
	}
	return result;
}

//iterative solution
node *merge(node *head1,node *head2){
	node *t=new node(1);
	node *temp=t;
	while(head1!=0 and head2!=0){
		if(head1->data<=head2->data){
			temp->next=head1;
			temp=temp->next;
			head1=head1->next;
		}
		else{
			temp->next=head2;
			temp=temp->next;
			head2=head2->next;
		}
	}
	if(head1==0)
		temp->next=head2;
	if(head2==0)
		temp->next=head1;
	temp=t->next;
	delete(t);
	return temp;
}
void traverse(node *head1){
	if(head1==0)
		return;
	cout<<head1->data<<" ";
	traverse(head1->next);
	return;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={1,2,3,4,5};
	vector<int> x={3,4,5,6};
	node *head1=create_list(v);
	node *head2=create_list(x);
	//write your code here
	node *head=merge(head1,head2);
	traverse(head);
	cout<<endl;
	return 0;
}