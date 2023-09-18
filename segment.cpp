//program to find minimum in range l-r

#include<bits/stdc++.h>
using namespace std;

int lazy[1000]={0};
//update lazy query
int queryLazy(int *tree,int s,int e,int l,int r,int index){
	//resolve node with lazy value
	if(lazy[index]!=0){
		tree[index]+=lazy[index];
		if(s!=e){
			lazy[2*index]+=lazy[index];
			lazy[2*index+1]+=lazy[index];
		}
		lazy[index]=0;
	}

	//no overlap
	if(l>e||r<s){
		return INT_MAX;
	}

	//complete overlap
	if(l>=s&&r<=e){
		return tree[index];
	}

	//partial overlap
	int mid=(s+e)/2;
	queryLazy(tree,s,e,l,r,2*index);
	queryLazy(tree,s,e,l,r,2*index+1);
	return min(tree[2*index],tree[2*index+1]);

}

//update lazy range
void updateLazy(int *tree,int s,int e,int l,int r,int incr,int index){
	//resolve node if non zero lazy value
	if(lazy[index]!=0){
		tree[index]+=lazy[index];
		//not a leaf node
		if(s!=e){
			lazy[2*index]=lazy[index];
			lazy[2*index+1]=lazy[index];
		}
		lazy[index]=0;
	}

	//out of bound
	if(l>e||r<s){
		return;
	}

	//complete overlap
	if(l>=s && r<=e){
		tree[index]+=incr;
		//non leaf node
		if(s!=e){
			lazy[2*index] += incr;
			lazy[2*index+1]+=incr;
		}
	}
	int mid=(s+e)/2;
	updateLazy(tree,s,mid,l,r,incr,2*index);
	updateLazy(tree,mid,e,l,r,incr,2*index+1);
	tree[index]=min(tree[2*index],tree[2*index+1]);
	return;
}
//updateRange
void updateRange(int *tree,int s,int e,int l,int r,int incr,int index){
	//no overlap
	if(l>e||r<s){
		return;
	}
	if(s==e){
		tree[index]+=incr;
		return;
	}

	int mid=(s+e)/2;
	updateRange(tree,s,mid,l,r,incr,2*index);
	updateRange(tree,mid+1,e,l,r,incr,2*index+1);
	tree[index]=min(tree[2*index],tree[2*index+1]);
	return;
}

//update at index
void updateNode(int *tree,int s,int e,int i,int incr,int index){
	//no overlap
	if(i>e||i<s){
		return;
	}
	if(s==e){
		tree[index]=incr;
		return;
	}

	int mid=(s+e)/2;
	updateNode(tree,s,mid,i,incr,2*index);
	updateNode(tree,mid+1,e,i,incr,2*index+1);
	tree[index]=min(tree[2*index],tree[2*index+1]);
	return;
}

//qurin on range
int query(int *tree,int s,int e,int qs,int qe,int index){
	//complete overlap
	if(s>=qs&&e<=qe){
		return tree[index];
	}

	//no overlap
	if(qe<s||qs>e){
		return INT_MAX;
	}

	//partial overlap
	int mid=(s+e)/2;
	int left=query(tree,s,mid,qs,qe,2*index);
	int right=query(tree,mid+1,e,qs,qe,2*index+1);
	return min(left,right);

}
//build tree
void build_tree(int *arr,int *tree,int s,int e,int index){
	//base case
	if(s==e){
		tree[index]=arr[s];
		return;
	}

	//recursive case
	int mid=(s+e)/2;
	build_tree(arr,tree,s,mid,2*index);
	build_tree(arr,tree,mid+1,e,2*index+1);
	tree[index]=min(tree[2*index],tree[2*index+1]);
	return;
}

int main(){
	int arr[]={1,3,2,-5,6,4};
	int n=sizeof(arr)/sizeof(int);
	int *tree=new int[4*n+1];
	build_tree(arr,tree,0,5,1);
	/*for(int i=1;i<=13;i++){
		cout<<tree[i]<<" ";
	}*/
	//cout<<endl;
	//update(tree,0,5,3,15,1);
	for(int i=0;i<6;i++){
		int ans=queryLazy(tree,0,5,i,i,1);
	    cout<<ans<<" ";
	}

	cout<<endl;
	//updateRange(tree,0,5,1,4,2,1);
	for(int i=0;i<6;i++){
		int ans=queryLazy(tree,0,5,i,i,1);
	    cout<<ans<<" ";
	}
	cout<<endl;
	return 0;
}