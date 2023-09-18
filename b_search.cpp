/*
Given a sorted array of integers and a key to be searched in the \
array. Print the position of the key in the array, if present. \
If it's not present in the array, report it. 
*/

#include<bits/stdc++.h>

using namespace std;
 

int bin_search(int A[], int left, int right, int k)
{
    
    while(left<=right){
        int mid=left+(right-left)/2;
        if(A[mid]==k){
            return mid;
        }else if(A[mid]>k){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return -1;
}
 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here

  return 0;
}
