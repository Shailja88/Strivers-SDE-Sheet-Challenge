//brute force approach
#include<bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
	vector<int>ans;
	vector<int>temp;
	temp.push_back(arr[0]);
	ans.push_back(arr[0]);
	for(int i=1;i<arr.size();i++){
       temp.push_back(arr[i]);
	   sort(temp.begin(),temp.end());
	   int x=temp.size();
	   int median=0;
	   if(x%2==0){
         median=(temp[x/2]+temp[x/2-1])/2;
		 ans.push_back(median);
	   }
	   else{
            ans.push_back(temp[x/2]);
	   }
	}
	return ans;
	// Write your code here 
}
#include<bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
	priority_queue<int,vector<int>,greater<int>>g;
	priority_queue<int>s;
	s.push(arr[0]);
	vector<int>ans;
	ans.push_back(arr[0]);
	for(int i=1;i<n;i++){
		int x=arr[i];
    if(s.size()>g.size()){
		if(x<s.top()){
			g.push(s.top());
			s.pop();
			s.push(x);
		}
		else 
		g.push(x);
		ans.push_back((s.top()+g.top())/2);
	}
	else{
		if(x<s.top())
		s.push(x);
		else{
			g.push(x);
			s.push(g.top());
			g.pop();
		}
		ans.push_back(s.top());
		
}
	}	return ans;}

