#include<bits/stdc++.h>

using namespace std;

struct que{
	int front,rear;
	int capacity;
	int size;
	int *arr;
};

struct que* createQue(int size){
	que *q=new que;
	if(q==0)
		return 0;
	q->front=q->rear=0;
	q->capacity=size;
	q->size=0;
	q->arr=new int[q->capacity*sizeof(int)];
	return q;
}

bool isEmpty(que *q){
	return q->front==q->rear;
}

bool isFull(que *q){
	return ((q->rear+1)%q->capacity==q->front);
}


void enque(struct que* q,int data){
	if(isFull(q)){
		cout<<"Que id full"<<endl;
		return;
	}
	q->rear=((q->rear+1)%q->capacity);
	q->arr[q->rear]=data;
	(q->size)++;
	return;
}

void deQue(struct que *q){
	if(isEmpty(q)){
		cout<<"Que is empty"<<endl;
		return;
	}
	q->front=(q->front+1)%q->capacity;
	(q->size)--;
	return;
}

int front(struct que *q){
	if(isEmpty(q))
		return -1;
	return q->arr[(q->front+1)%q->capacity];
}

int main(){
	que *q=createQue(5);
	//cout<<q->capacity<<endl;
	//cout<<q->front<<endl;
	//cout<<q->rear<<endl;
	enque(q,3);
	enque(q,4);
	enque(q,8);
	enque(q,3);
	enque(q,4);
	enque(q,8);
	cout<<q->size<<endl;
}