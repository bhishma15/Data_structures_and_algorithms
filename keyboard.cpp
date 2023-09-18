/*
Imagine you have a special keyboard with the following keys: 
Key 1:  Prints 'A' on screen
Key 2: (Ctrl-A): Select screen
Key 3: (Ctrl-C): Copy selection to buffer
Key 4: (Ctrl-V): Print buffer on screen appending it
                 after what has already been printed. 

If you can only press the keyboard for N times (with the above four
keys), write a program to produce maximum numbers of A's. That is to
say, the input parameter is N (No. of keys that you can press), the 
output is M (No. of As that you can produce).

*/

#include<bits/stdc++.h>

using namespace std;
 

//my approach
int solve(int count,int buff,int n,int mode){
	if(n<0)
		return 0;
	if(n==0)
		return count;
	int x=solve(count+1,0,n-1,0);
	int y;
	if(mode==0){
		buff=count;
		y=solve(count+buff,buff,n-3,1);
	}else{
		y=solve(count+buff,buff,n-1,1);
	}
	return max(x,y);
}
 
 //optimal
 int findoptimal(int N) 
{ 
    // The optimal string length is N when N is smaller than 7 
    if (N <= 6) 
        return N; 
  
    // Initialize result 
    int max = 0; 
  
    // TRY ALL POSSIBLE BREAK-POINTS 
    // For any keystroke N, we need to loop from N-3 keystrokes 
    // back to 1 keystroke to find a breakpoint 'b' after which we 
    // will have Ctrl-A, Ctrl-C and then only Ctrl-V all the way. 
    int b; 
    for (b = N - 3; b >= 1; b--) { 
  
        // If the breakpoint is s at b'th keystroke then 
        // the optimal string would have length 
        // (n-b-1)*screen[b-1]; 
        int curr = (N - b - 1) * findoptimal(b); 
        if (curr > max) 
            max = curr; 
    } 
    return max; 
} 

int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here
  int ans=solve(0,0,7,0);
  cout<<ans<<endl;
  return 0;
}