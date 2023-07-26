//using map and  multimap
#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    int r=0;
    vector<int>ans;
    map<int,int>mp;
    for(auto in:arr){
        mp[in]++;
    }
    multimap<int,int>mp1;
    for(auto in:mp){
        mp1.insert({-1*in.second,in.first});

    }
    for(auto in:mp1){
        r++;
        ans.push_back(in.second);
        if(r==k)break;
    }
  return ans;
}

class Solution {
public:
//using priority queue and map
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
       map<int,int>mp;
       for(auto in:nums){
           mp[in]++;
       }
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       for(auto in:mp){
           pq.push({in.second,in.first});
           if(pq.size()>k)
           pq.pop();
       }
     while(!pq.empty()){
         pair<int,int>temp=pq.top();
         ans.push_back(temp.second);
         pq.pop();
     }
     return ans;
    }
};
