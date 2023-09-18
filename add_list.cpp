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

void traverse(node *head1){
	if(head1==0)
		return;
	cout<<head1->data<<" ";
	traverse(head1->next);
	return;
}

void addList(node *list1,node *list2,int *carry,node **result){
	int sum=0;
	if(!list1)
		return;

	addList(list1->next,list2->next,carry,result);
	sum=list1->data+list2->data+(*carry);
	*carry=sum/10;
	sum=sum%10;
	node *temp=new node(sum);
	temp->next=*result;
	*result=temp;
	return;
}

void addRemain(node *list1,int *carry,node  **result,int diff){
	int sum=0;
	if(!list1||diff==0){
		return;
	}
	addRemain(list1->next,carry,result,diff-1);
	sum=list1->data+(*carry);
	*carry=sum/10;
	sum=sum%10;
	node *temp=new node(sum);
	temp->next=(*result);
	*result=temp;
	return;
}

void addWrapper(node *list1,node *list2,int *carry,node **result){
	int len1=0,len2=0;
	node *curr=list1;
	while(curr){
		curr=curr->next;
		len1++;
	}

	curr=list2;
	while(curr){
		curr=curr->next;
		len2++;
	}

	if(len1<len2){
		node *temp=list1;
		list1=list2;
		list2=temp;
	}
	curr=list1;
	int diff=abs(len1-len2);
	while(diff--){
		curr=curr->next;
	}
	addList(curr,list2,carry,result);
	diff=abs(len1-len2);
	addRemain(list1,carry,result,diff);
	if(*carry){
		node *temp=new node(*carry);
		temp->next=(*result);
		*result=temp;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={4,1,2,5,3};
	vector<int> x={2,5,3};
	node *head1=create_list(v);
	node *head2=create_list(x);
	//write your code here
	node **result;
	int carry=0;
	addWrapper(head1,head2,&carry,result);
	traverse(*result);
	return 0;
}