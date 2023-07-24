/*TC=O(n^2)
  */
#include<bits/stdc++.h>
using namespace std;
bool isPossible(int mindis,vector<int>&stalls,int cows,int n){
    int cnt_cows=1;
    int dis=stalls[0];
      for(int i=1;i<n;i++){
        
          if(stalls[i]-dis>=mindis){
              cnt_cows++;
              dis=stalls[i];
          }
            if(cnt_cows>=cows)return true;
         }
      return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //k number of cows
    
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    for(int i=1;i<=(stalls[n-1]-stalls[0]);i++){
        if(isPossible(i,stalls,k,n)==false){
          return i-1;
        }
        
    }
   return (stalls[n-1]-stalls[0]);
}


/////
#include<bits/stdc++.h>
using namespace std;
bool isPossible(int mindis,vector<int>&stalls,int cows,int n){
    int cnt_cows=1;
    int dis=stalls[0];
      for(int i=1;i<n;i++){
        
          if(stalls[i]-dis>=mindis){
              cnt_cows++;
              dis=stalls[i];
          }
            if(cnt_cows>=cows)return true;
         }
      return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //k number of cows
    
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int low=0;
    int high=stalls[n-1]-stalls[0];
    while(low<=high){
      int  mid=(low+high)/2;
      if(isPossible(mid,stalls,k,n)){
        low=mid+1;
      }
      else{
        high=mid-1;
      }
    }
   return high;
}
