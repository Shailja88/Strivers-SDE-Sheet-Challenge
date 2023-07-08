/*TC=O(n^2)
  SC=O(1)
  */
//BRUTE FORCE
int subarraysWithSumK(vector < int > a, int b) {
    // generate all the subarrays
    int  cnt=0;
    for(int i=0;i<a.size();i++){
        int  prev=0;
        for(int j=i;j<a.size();j++){
           prev=a[j]^prev;
           if(prev==b)cnt++;
        }
        
         }
    return cnt;

}
#include<bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    //TC=O(nlogn) or O(n)
    //SP=O(n)
    int xr=0;
    map<int,int>mpp;
    int cnt=0;
    mpp[xr]++;
for(int i=0;i<a.size();i++){
    xr=xr^a[i];
    int x=xr^b;
    cnt+=mpp[x];
    mpp[xr]++;
}
return cnt;
}
