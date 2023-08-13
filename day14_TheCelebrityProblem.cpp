#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	 stack<int>st;
	 for(int i=0;i<n;i++){
		 st.push(i);
	 }
     while(st.size()>1){
        int x=st.top();st.pop();
		int  y=st.top();st.pop();
		if(knows(x,y))st.push(y);
		else if(!knows(x,y)){
			st.push(x);
		}
     }
	 int pot=st.top();
	for(int i=0;i<n;i++){
   if(pot!=i){
	   if(knows(pot,i)||(!knows(i,pot)))
	   return -1;
   }
  
}
return pot;
}
