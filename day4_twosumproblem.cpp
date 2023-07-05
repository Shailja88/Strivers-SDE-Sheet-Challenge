/********************************************************************codestudio*****************************************************************
BRUTE FORCE APPROACH
TC=O(n^2)
SC=O(1)
*/
#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   vector<vector<int>>v;
   for(int i=0;i<arr.size()-1;i++){
      
      for(int j =i+1;j<arr.size();j++){
         if((arr[i]+arr[j])==s){
            int x=max(arr[i],arr[j]);
            int y=min(arr[i],arr[j]);
            v.push_back({y,x});
         }
      }
   }
   sort(v.begin(),v.end());
   return v;
}



/***********************************************************************LEETCODE************************************************************************************
BRUTE FORCE APPROACH
TC=O(n^2)
SC=O(1)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ///brute force approach
        vector<int>ans;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                     break;
                }
            }
        }
        return ans;
    }
};
/*BETTER SOLUTION
  hashing
  TC=O(n*(map ki time complexity));
  if(ordered map) then O(nlogn)
  if(unordered map) then O(n) or O(n^2)
  SC=O(n)
    */


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int remain=target-num;
            if(mp.find(remain)!=mp.end()){
                return{i,mp[remain]};
            }
            mp[num]=i;
        }
        return{-1,-1};
    }
};
