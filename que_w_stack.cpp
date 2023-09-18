/*
queue implementation with stack
*/

#include<bits/stdc++.h>

using namespace std;
 

class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

/* The method push to push element into the queue */
void StackQueue :: push(int x)
 {
        // Your Code
        s1.push(x);
        return;
 }

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
        // Your Code  
        if(s1.empty()&&s2.empty())
        return -1;
        if(s2.empty())
        {
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val=s2.top();
        s2.pop();
        return val;
}
 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here

  return 0;
}