/*
TC=O(n!*n)
SC=O(2n)*/
class Solution {
public:
    void fun(vector<vector<int>>&ans,int n,vector<int>&nums,vector<int>&permu,vector<bool>&dp){
        if(permu.size()==n){
            ans.push_back(permu);
            return;
        }
        for(int i=0;i<n;i++){
         if(!dp[i]){
             permu.push_back(nums[i]);
             dp[i]=true;
            fun(ans,n,nums,permu,dp);
            dp[i]=false;
            permu.pop_back();
         }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        //method 1
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>permu;
        vector<bool>dp(n,false);
        fun(ans,n,nums,permu,dp);
        return ans;
    }
};


#include <bits/stdc++.h> 
void func(vector<string>&ans,int n,string &nums,string &permu,vector<bool> &dp){
     if(permu.size()==n){
            ans.push_back(permu);
            return;
        }
        for(int i=0;i<n;i++){
         if(!dp[i]){
             permu.push_back(nums[i]);
             dp[i]=true;
            func(ans,n,nums,permu,dp);
            dp[i]=false;
            permu.pop_back();
         }
        }
}
vector<string> findPermutations(string &nums) {
    int n=nums.size();
        vector<string>ans;
        string permu;
        vector<bool>dp(n,false);
        func(ans,n,nums,permu,dp);
        return ans;
}
/*
TC=O(n!*n)
SC=O(2n)*/



/******
TC=O(n!*n)
SC=O(1)****/
class Solution {
public:
void func(vector<vector<int>>&ans,vector<int>&nums,int ind){
     if(ind==nums.size()){
         ans.push_back(nums);
         return;
     }
     for(int i=ind;i<nums.size();i++){
         swap(nums[i],nums[ind]);
         func(ans,nums,ind+1);
         swap(nums[i],nums[ind]);
     }
}
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>ans;
    func(ans,nums,0);
    return ans;
    }
};
