#include<bits/stdc++.h>

using namespace std;

void build_tree(int *tree,int arr[],int n){
	int size=4*n+1;
	for(int k=1;k<size;k++){
		int a,b;
		a=k-(k&-k)+1;
		b=k;
		if(a>=1&&b<=n){
			int sum=0;
			for(int i=a;i<=b;i++){
				sum += arr[i];
			}
			tree[k]=sum;
		}
	}
}

//finds sum of value from 1 to kth index
int sum(int *tree,int k){
	int sum=0;
	while(k>=1){
		sum += tree[k];
		k -= k&-k;
	}

	return sum;
}

//INCREMENT VALUE AT INDEX
void add(int *tree,int index,int value,int n){
	while(index<=n){
		tree[index]+=value;
		index += index&-index;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//write your code here
		int n=9;
		int arr[n]={0,1,3,4,8,6,1,4,2};
		int *tree=new int[4*n+1];
		build_tree(tree,arr,n);
		/*for(int i=1;i<=8;i++){
			cout<<tree[i]<<" ";
		}*/
		int ans=sum(tree,7);
		cout<<ans<<endl;
	return 0;
}