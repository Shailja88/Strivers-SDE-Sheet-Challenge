//Brute force approach
#include <bits/stdc++.h>
bool cmp(int a,int b){
	return a>b;
} 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
	vector<int>ans;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans.push_back(a[i]+b[j]);
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	vector<int>f;
	for(int i=0;i<k;i++){
		f.push_back(ans[i]);
	}
	return f;
}
//using priority queue and pair 
#include <bits/stdc++.h> 
typedef pair<int,int> p;
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	vector<int>ans;
	set<p>st;
	priority_queue<pair<int,p>>pq;/////[{sum,{a(index),b(index)}}]
	/* sum=a[n-1]+b[n-1]
	a(index)=n-1;
	b(index)=n-1;
	
	*/
	pq.push({a[n-1]+b[n-1],{n-1,n-1}});
	st.insert({n-1,n-1});
	while(k>0){
		pair<int,p>temp=pq.top();
		int sum=temp.first;
		int x=temp.second.first;//index of a
		int y=temp.second.second;//index of b
		ans.push_back(sum);
		pq.pop();
		if(st.find({x-1,y})==st.end()){
			pq.push({a[x-1]+b[y],{x-1,y}});
			st.insert({x-1,y});
		}
		if(st.find({x,y-1})==st.end()){
			pq.push({a[x]+b[y-1],{x,y-1}});
			st.insert({x,y-1});
		}
		k=k-1;
	}
	
	return ans;

}
