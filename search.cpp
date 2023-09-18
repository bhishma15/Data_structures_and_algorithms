/*
Given a sorted and rotated array A of N distinct elements which is \
rotated at some point, and given an element K. The task is to find \
the index of the given element K in the array A.
*/

#include<iostream>
using namespace std;
int search(int arr[],int start,int end,int x){
    if(end<start)
    return -1;
    int mid=start+(end-start)/2;
    if(arr[mid]==x){
        return mid;
    }
    else if(arr[start]<=arr[mid]){
        if(x<=arr[mid]&&x>=arr[start]){
        return search(arr,start,mid-1,x);
        }
        else{
            return search(arr,mid+1,end,x);
        }
    }else{
        if(x>=arr[mid]&&x<=arr[end]){
        return search(arr,mid+1,end,x);
        }
        else{
            return search(arr,start,mid-1,x);
        }
    }
    
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int k;
        cin>>k;
        int ind=search(arr,0,n-1,k);
        cout<<ind<<endl;
	}
	
	
	return 0;
}