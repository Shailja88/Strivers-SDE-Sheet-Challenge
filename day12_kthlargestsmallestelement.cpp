//using arrays
#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &v, int n, int k)
{
	sort(v.begin(),v.end());
	return {v[k-1],v[n-k]};
}

//using max heap
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
//using min and max heap 
#include<bits/stdc++.h>
#include<queue>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	//for largest minheap
	//for smallest max heap
	priority_queue<int>mxheap;
	priority_queue<int,vector<int>,greater<int>>mnheap;
	for(auto in:arr){
		mxheap.push(in);
		mnheap.push(in);
		if(mxheap.size()>k){
			mxheap.pop();
			mnheap.pop();
		}
	}
	int x=mxheap.top();
	int y=mnheap.top();
	return {x,y};
}
