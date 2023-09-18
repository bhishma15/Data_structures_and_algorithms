#include<bits/stdc++.h>
using namespace std;

struct heap{
	int *arr;
	int size;
	int capacity;
};

//create heap of given capacity
struct heap* createHeap(int capacity){
	heap *h=new heap;
	if(h==0)
		return 0;
	h->size=0;
	h->capacity=capacity;
	h->arr=new int[capacity*sizeof(int)];
	return h;
}

//find parent of node
int parent(heap* h,int i){
	if(i<=0||i>=h->size){
		return -1;
	}
	return (i-1)/2;
}

//get left child
int getLC(heap* h,int i){
	int l=2*i+1;
	if(l>=h->size)
		return -1;
	return l;
}

//get right child
int getRC(heap* h,int i){
	int r=2*i+2;
	if(r>=h->size)
		return -1;
	return r;
}

//get maximum element
int getMax(heap* h){
	if(h->size==0)
		return -1;
	return h->arr[0];
}

//heapifying from top to bottem
void percolateDown(heap *h,int i){
	int l,r,temp;
	l=getLC(h,i);
	r=getRC(h,i);
	int max;
	if(l!=-1&&h->arr[l]>h->arr[i]){
		max=l;
	}else{
		max=i;
	}
	if(r!=-1&&h->arr[r]>h->arr[max]){
		max=r;
	}
	if(max!=i){
		temp=h->arr[i];
		h->arr[i]=h->arr[max];
		h->arr[max]=temp;
		percolateDown(h,max);
	}
	
}

//delete max element in heap
int deleteMax(heap* h){
	if(h->size<=0){
		return -1;
	}
	int data=h->arr[0];
	h->arr[0]=h->arr[h->size-1];
	percolateDown(h,0);
	return data;
}

//resize the heap
void reSize(heap* h){
	int *temp=h->arr;
	h->arr=new int[h->capacity*2*sizeof(int)];
	for(int i=0;i<h->capacity;i++){
		h->arr[i]=temp[i];
	}
	h->capacity*=2;
	delete(temp);
}
//insert element in heap
void insert(heap* h,int data){
	if(h->size==h->capacity){
		reSize(h);
	}
	h->size++;
	int i=h->size-1;
	while(i>=0&&data>h->arr[i]){
		h->arr[i]=h->arr[(i-1)/2];
		i=(i-1)/2;
	}
	h->arr[i]=data;
	return;
}



//build heap from array
void buildHeap(heap *h,int arr[],int n){
	if(h==0)
		return ;
	while(h->capacity<n){
		reSize(h);
	}
	for(int i=0;i<n;i++){
		h->arr[i]=arr[i];
	}
	h->size=n;
	for(int i=(h->size-1)/2;i>=0;i--){
		percolateDown(h,i);
	}
	return;
}

void heapSort(int *a,int n){
	heap *h=createHeap(n);
	if(h==0)
		return;
	buildHeap(h,a,n);
	for(int i=n-1;i>0;i--){
		int temp=h->arr[0];
		h->arr[0]=h->arr[i];
		h->arr[i]=temp;
		h->size--;
		percolateDown(h,0);
	}

	for(int i=0;i<n;i++){
		a[i]=h->arr[i];
	}
	return;
}


//find kth largest element in max heap
int kth_largest(heap* h,int k){
	for(int i=0;i<k-1;i++){
		deleteMax(h);
	}
	return getMax(h);
}

int main(){
	int arr[]={5,1,3,2,6,4};
	heap *h=createHeap(6);
	buildHeap(h,arr,6);
	//write your code here
	int ans=kth_largest(h,4);
	cout<<ans<<endl;
}