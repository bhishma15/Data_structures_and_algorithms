#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next;
};

void bubble(node *head,int n){
	if(head==0)
		return;
	for(int i=0;i<n-1;i++){
		node *temp=head;
		while(temp&&temp->next){
			if(temp->data>temp->next->data){
				int val=temp->data;
				temp->data=temp->next->data;
				temp->next->data=val;
			}
			temp=temp->next;
		}
	}
	return;
}

void split(node *head,node **x,node **y){
	node *slow,*fast;
	slow=head;
	fast=head->next;
	while(fast!=0){
		fast=fast->next;
		if(fast!=0){
			slow=slow->next;
			fast=fast->next;
		}
	}
	*x=head;
	*y=slow->next;
	slow->next=0;
	return;
}

node *sortedMerge(node *a,node *b){
	node *res=0;
	if(a==0)
		return b;
	else if(b==0)
		return a;
	if(a->data<b->data){
		res=a;
		res->next=sortedMerge(a->next,b);
	}else{
		res=b;
		res->next=sortedMerge(a,b->next);
	}
	return res;
}
void mergeSort(node **listHead){
	node *head,*a,*b;
	head=*listHead;
	if(head==0||head->next==0)return;
	split(head,&a,&b);
	mergeSort(&a);
	mergeSort(&b);

	*listHead=sortedMerge(a,b);
}

int main(){
	node *head,*temp;
	temp=new node;
	temp->data=20;
	temp->next=0;
	head=temp;
	temp=new node;
	temp->data=10;
	temp->next=0;
	head->next=temp;
	temp=new node;
	temp->data=30;
	temp->next=0;
	head->next->next=temp;

	temp=head;
	while(temp!=0){
		cout<<temp->data<<" ";
		temp=temp->next;
	}

	mergeSort(&head);

	temp=head;
	while(temp!=0){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
