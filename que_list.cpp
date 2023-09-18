#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};

struct que{
	int size;
	node *front;
	node *rear;
};

que* createQ(){
	que *q=new que;
	q->front=NULL;
	q->rear=NULL;
	q->size=0;
	return q;
}

bool isEmpty(que *q){
	return q->front==NULL;
}

void enQ(que *q,int data){
	node *temp=new node;
	temp->data=data;
	temp->next=0;
	if(q->rear==0){
		q->rear=temp;
	}
	else{
		q->rear->next=temp;
	}
	if(q->front==0)
		q->front=q->rear;
	return;
}

void deQ(que *q){
	if(isEmpty(q)){
		cout<<"Que is empty"<<endl;
		return;
	}
	q->front=q->front->next;
	return;
}

int front(que *q){
	if(isEmpty(q)){
		cout<<"Que is empty"<<endl;
		return -1;
	}
	return q->front->data;
}


int main(){
	que *q=createQ();
	enQ(q,3);
	enQ(q,4);
	if(isEmpty(q)){
		cout<<"yes"<<endl;
	}
	cout<<front(q)<<endl;
	deQ(q);
	cout<<front(q)<<endl;
}