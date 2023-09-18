/*
Given an input stream of N integers. The task is to insert these \
numbers into a new stream and find the median of the stream formed \
by each insertion of X to the new stream.
*/

#include<bits/stdc++.h>
using namespace std;
void solve(double arr[],int n){
    priority_queue<double> mx;
    priority_queue<double ,vector<double> , greater<double> > mn;
    double med;
    med=arr[0];
    cout<<arr[0]<<endl;
    mx.push(arr[0]);
    for(int i=1;i<n;i++){
        if(mx.size()>mn.size()){
            if(arr[i]<med){
                mn.push(mx.top());
                mx.pop();
                mx.push(arr[i]);
            }else{
                mn.push(arr[i]);
            }
            med=(mn.top()+mx.top())/2.0;
        }else if(mx.size()<mn.size()){
            if(arr[i]>med){
                mx.push(mn.top());
                mn.pop();
                mn.push(arr[i]);
            }else{
                mx.push(arr[i]);
            }
            med=(mn.top()+mx.top())/2.0;
        }else{
            if(arr[i]<med){
                mx.push(arr[i]);
                med=mx.top();
            }else{
                mn.push(arr[i]);
                med=mn.top();
            }
        }
        cout<<med<<endl;
    }
    
    return;
}
int main()
 {
	//code
	int n;
	cin>>n;
	double arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	solve(arr,n);
	cout<<endl;
	return 0;
}