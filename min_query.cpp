#include<bits/stdc++.h>
using namespace std;

int lazy[1000]={0};

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
		tree[index]=incr;
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
	int n,q;
	cin>>n>>q;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int *tree=new int[4*n+1];
	build_tree(arr,tree,0,n-1,1);
	while(q--){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==1){
			int ans =queryLazy(tree,0,n-1,b-1,c-1,1);
			cout<<ans<<endl;
		}
		else{
			updateLazy(tree,0,n-1,b-1,b-1,c-1,1);
		}
	}
}