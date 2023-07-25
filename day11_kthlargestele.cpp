//brute force approach
// TC=O(nlogn) SC=O(1);
#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &v, int n, int k)
{
	sort(v.begin(),v.end());
	return {v[k-1],v[n-k]};
}

///priority queue
#include<bits/stdc++.h>
#include<queue>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	  priority_queue<int>pq(arr.begin(),arr.end());
	int x=0;int y=0;
    int small=0;int large=0;int r=n-k+1;
	while(n--){
    x++;
	y++;
	if(x==k){
	large=pq.top();	
	}
	if(y==r)
	small=pq.top();
	pq.pop();
	}
	return {small,large};
}
