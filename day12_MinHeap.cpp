//using stl library 
#include <bits/stdc++.h> 
#include<queue>
//short cut not for interview dusra kro ache s detail m pdh ke
priority_queue<int,vector<int>,greater<int>>pq;
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(q[i][0]==0){
            pq.push(q[i][1]);
        }
        else if(q[i][0]==1){
            ans.push_back(pq.top());//printing the minimum element 
            pq.pop();//removed the minimum element
        }
    }
    while(!pq.empty()){
        pq.pop();//removed remaining element 
    }
    return ans;
}

///using functions only
#include <bits/stdc++.h>
void heapify(vector<int>&v,int i){
    int small=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<v.size() && v[left]<v[small]){
        small=left;
    }
    if(right<v.size()&& v[right]<v[small]){
        small=right;
    }
    if(small!=i){
        swap(v[small],v[i]);
        heapify(v,small);
    }
}
int deleteEle(vector<int>&v){
    int ans=-1;
    if(v.size()==0)return ans;
    ans=v[0];
    if(v.size()==1){
        v.pop_back();
        return ans;
    }
    v[0]=v[v.size()-1];
    v.pop_back();
    heapify(v,0);
    return ans;
}
void insert(vector<int>&v,int x){
  v.push_back(x);
  if(v.size()==1)return;
  int i=v.size()-1;
  int pi=(i-1)/2;
  while(i!=0 && v[pi]>v[i]){
  swap(v[pi],v[i]);
  i=pi;
  pi=(i-1)/2;
  }
}
vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int>v;//heap wala vector 
    vector<int>ans;
    for(int i=0;i<q.size();i++){
        if(q[i][0]==0){
            insert(v,q[i][1]);
        }
        else{
            ans.push_back(deleteEle(v));
        }
    }

return ans;
}
