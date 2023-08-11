/*Brute Force
TC=O(n^2)
SC=O(K)
*/

#include<bits/stdc++.h>

int value(vector<int>&arr,int ini,int fin){
      int r=INT_MIN;
   for(int i=ini;i<=fin;i++){
       r=max(arr[i],r);
   }

  return r;
}
vector<int> maxSlidingWindow(vector<int> &arr, int n, int k){
    /*Brute Force*/
    vector<int>ans;
    for(int i=0;i<=n-k;i++){
      ans.push_back(value(arr,i,i+k-1));
    }
    return ans;
}

#include<bits/stdc++.h>
/*using dequeue 
TC=O(n)
SC=O(n)
*/
vector<int> maxSlidingWindow(vector<int> &arr, int n, int k){
vector<int>ans;
deque<int>dq;
for(int i=0;i<n;i++){

    if(!dq.empty() && dq.front()==i-k)dq.pop_front();
    while(!dq.empty() && arr[i]>=arr[dq.back()])dq.pop_back();
    dq.push_back(i);
    if(i>=k-1)ans.push_back(arr[dq.front()]);
}
return ans;
}
