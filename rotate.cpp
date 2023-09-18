/*

Given a singly linked list of size N. The task is to rotate the \
linked list counter-clockwise by k nodes, where k is a given \
positive integer smaller than or equal to length of the linked list.
*/

#include<bits/stdc++.h>

using namespace std;
 

Node* rotate(Node* head, int k)
{
    // Your code here
    if(head==0)
    return head;
    Node *start,*end;
    start=end=head;
    while(end->next){
        end=end->next;
    }
    while(k--){
        end->next=start;
        start=start->next;
        end=end->next;
        end->next=0;
    }
    return start;
}

 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here

  return 0;
}