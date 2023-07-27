//1.brute force approach 
#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here.
    vector<int>ans;
    for(int i=0;i<kArrays.size();i++){
        for(int j=0;j<kArrays[i].size();j++){
            ans.push_back(kArrays[i][j]);
        }
    }
sort(ans.begin(),ans.end());
return ans;
}
//2nd approach
#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here.
    vector<int>ans; 
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<kArrays.size();i++){
         for(auto in:kArrays[i]){
        pq.push(in);
    }
    }
   
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}


//3rd approach
#include <bits/stdc++.h> 
class data{
    public:
    int val,row,col;
    data(int v,int r,int c){
        val=v;
        row=r;
        col=c;
    }
    
};
struct cmp{
     bool operator()(data &d1,data &d2){
      return d1.val>d2.val;
     }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int>ans;
    priority_queue<data ,vector<data>,cmp>pq;
    for(int i=0;i<k;i++){
        data d(kArrays[i][0],i,0);
        pq.push(d);
    }
    while(!pq.empty()){
        data curr=pq.top();
        pq.pop();
        int v=curr.val;
        int ap=curr.row;
        int vp=curr.col;
        ans.push_back(v);
        if(vp+1<kArrays[ap].size()){
            data temp(kArrays[ap][vp+1],ap,vp+1);
            pq.push(temp);
        }
    }
    return ans;
}
