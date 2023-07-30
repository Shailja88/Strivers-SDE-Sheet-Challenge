//using priority_queue 
#include <bits/stdc++.h> 
void sortStack(stack<int> &st)
{
	// Write your code here
	priority_queue<int,vector<int>,greater<int>>pq;
	while(!st.empty()){
		int r=st.top();
		st.pop();
		pq.push(r);
	}
	while(!pq.empty()){
		st.push(pq.top());
		pq.pop();
	}
	return;
}
//recursion 
#include <bits/stdc++.h> 
void insert_correct_position(int x,stack<int>&st){
	if(st.size()==0 || st.top()<x)
	{st.push(x);
	}
	else{
		int a=st.top();
		st.pop();
		insert_correct_position(x,st);
		st.push(a);
	}
}
void reverse(stack<int>&st){
	if(st.size()>0){
		int x=st.top();
		st.pop();
		reverse(st);
		insert_correct_position(x,st);
	}
	
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	reverse(stack);
	
	
}
