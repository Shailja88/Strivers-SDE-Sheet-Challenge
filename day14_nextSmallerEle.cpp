
void immediateSmaller(vector<int>& a)
{
	// Write your code here.
	for(int i=0;i<a.size();i++){
		if(i==a.size()-1)
		a[i]=-1;
		if(a[i]>a[i+1]){
         a[i]=a[i+1];
		}
		else{
			a[i]=-1;
		}
	}
	return;
}
//using stack
#include<bits/stdc++.h>
void immediateSmaller(vector<int>& a)
{	//USING STACK PEECHHE S JAO 
    int n=a.size();
	stack<int>s;
	s.push(-1);
	for(int i=n-1;i>=0;i--){
		int curr=a[i];
		if(s.top()<a[i])
		{
			a[i]=s.top();
		}
		else{
			a[i]=-1;
		}
		s.push(curr);
	}
	return;
}

/***********************************************
INTERVIEW BIT***/
#include<bits/stdc++.h>
vector<int> Solution::prevSmaller(vector<int> &a) {
      stack<int>s;
       s.push(a[0]);
    for(int i=1;i<a.size();i++){
        while(!s.empty() &&  s.top()>=a[i]){
           s.pop();
        }
        int x=(s.empty())?-1:s.top();
        s.push(a[i]);
        a[i]=x;
        
    }
    a[0]=-1;
    return a;
}
