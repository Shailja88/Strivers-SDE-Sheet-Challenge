#include<bits/stdc++.h>
using namespace std;
 bool cmp(pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;
    }
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
   int n=start.size();
    vector<pair<int,int>>v;
    for(int i=0;i<start.size();i++){
    v.push_back({start[i],finish[i]});

    }
       sort(v.begin(),v.end(),cmp);
    int take=1;
 int r=v[0].second;
 for(int i=1;i<n;i++){
     if(r<=v[i].first){
         take++;
         r=v[i].second;
     }
 }
 return take;
}
