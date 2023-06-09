//codestudio
#include <bits/stdc++.h> 
using namespace std;
long long int maxSubarraySum(int arr[] , int n)
{
  
    long long int sum=0;
    long long int maxi=0;
   for(int i=0;i<n;i++){
       sum=sum+arr[i];
       if(sum<0)sum=0;

       if(maxi>sum){
           maxi=maxi;
       }
       else{
           maxi=sum;
    //    maxi=max(sum,maxi); 
    } 
   }   
return maxi;
}

//leetcode
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int flag=0;
        int maxi=INT_MIN;
   
        for(int i=0;i<nums.size();i++){
       
            sum=sum+nums[i];
            if(sum<0){
                sum=0;
                
            }
            else{
                flag=1;
                maxi=max(sum,maxi);
            }
        }
        if(flag==0){
            for(int i=0;i<nums.size();i++){
                maxi=max(maxi,nums[i]);
            }
        }
        return maxi;
    }
};
