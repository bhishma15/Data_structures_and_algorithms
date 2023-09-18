/*
Given a singly linked list of N nodes. The task is to find the middle of the linked list.\
 For example, if given linked list is 1->2->3->4->5 then the output should be 3.
If there are even nodes, then there would be two middle nodes, we need to print the second middle element.\
 For example, if given linked list is 1->2->3->4->5->6 then the output should be 4.
*/

#include<bits/stdc++.h>

using namespace std;
 

int getMiddle(Node *head)
{
   // Your code here
   if(head==0);
   -1;
   Node *slow,*fast;
   slow=head;
   fast=head;
   while(fast&&fast->next){
       slow=slow->next;
       fast=fast->next->next;
   }
   return slow->data;
}

int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here

  return 0;
}