class Solution {
public:
void fun(vector<int>&candidates,vector<vector<int>>&ans,vector<int>&dp,int target,int ind,int n){
    if(ind==n){
        if(target==0){
            ans.push_back(dp);
        }
        return;
    }
    if(candidates[ind]<=target){
        dp.push_back(candidates[ind]);
        fun(candidates,ans,dp,target-candidates[ind],ind,n);//take
        dp.pop_back();
    }
    fun(candidates,ans,dp,target,ind+1,n);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       /*pick and not pick
       using recursion 
       TC=O(2^t*k)
       SC=O(kx)hypothetical
       CONDITION is given that we can pick one element any number of times 
       so in function call if we choose to pick that element next time we will call function remaining at previous position 
       so index will not increase 
       On the other hand if we 
       */
       int n=candidates.size();
       vector<vector<int>>ans;
       vector<int>dp;

       fun(candidates,ans,dp,target,0,n);
       return ans;
        
    }
};


void fun(vector<vector<int>>&ans,vector<int>&arr,int n,int  target,vector<int>dp,int i){
    if(i==n){
        if(target==0){
            ans.push_back(dp);
        }
        return;
    }
    // if(target>=arr[i]){
        //take
        dp.push_back(arr[i]);
        fun(ans,arr,n,target-arr[i],dp,i+1);
        dp.pop_back();
    // }
    fun(ans,arr,n,target,dp,i+1);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int target)
{
    // Write your code here.
    vector<vector<int>>ans;
    vector<int>dp;
    fun(ans,arr,n,target,dp,0);
    return ans;

}
