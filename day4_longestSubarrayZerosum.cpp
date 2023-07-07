/*BRUTE FORCE 
TC=O(n^2)
SC=O(1)
*/
#include <bits/stdc++.h>
int LongestSubsetWithZeroSum(vector < int > arr) {
int ans=0;
for(int i=0;i<arr.size();i++){
  int cnt=0;
  int sum=0;
  for(int j=i;j<arr.size();j++){
     sum=sum+arr[j];
        cnt++;
       if(sum==0)
       ans=max(cnt,ans);
 }
}
return ans;
}

/*************************************
OPTIMAL APPROACH
if array has + and - we can use this 
[-1,0,1,2,-1,-4]
TC=O(nlogn) // ordered map
TC=O(n) or O(n^2) //for unordered_map (no collision or collision)
SC=O(n)
*/
#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  int n=arr.size();
  map<long long ,int>presum;
long long sum=0;
  int maxLen=0;
  int cnt=0;
  for(int i=0;i<n;i++){
    sum+=arr[i];
    if(sum==0){
      cnt=i+1;
      maxLen=max(maxLen,cnt);
    }
    else if(presum.find(sum)!=presum.end()){
      cnt=i-presum[sum];
      maxLen=max(maxLen,cnt);
    }
    else if(presum.find(sum)==presum.end()){
      presum[sum]=i;
    }
    
  }
return maxLen;
}
