//codestudio
#include<bits/stdc++.h>
bool cmp(pair<int,int>&a,pair<int,int>&b){
    return a.second<b.second;///increasing order 
}
int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    int n=start.size();
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        v.push_back({start[i],end[i]});
    }
    sort(v.begin(),v.end(),cmp);//sort with respect to second value in increasing  order 
    int cnt=1;
    int rambha=v[0].second;
    for(int i=1;i<n;i++){
        if(v[i].first>rambha){
            rambha=v[i].second;
            cnt++;
        }
    }
    return cnt;
}
