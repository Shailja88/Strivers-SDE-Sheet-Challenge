/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates
where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.*/

 



class Solution {
public:
void func(vector<vector<int>>&ans,vector<int>&candidates,vector<int>&ds,int target,int ind,int n){

  
    if(target==0){
        ans.push_back(ds);
        return;
    }
    for(int i=ind;i<n;i++){
        if(i!=ind && candidates[i]==candidates[i-1])continue;
        if(candidates[i]>target)break;
        ds.push_back(candidates[i]);
        func(ans,candidates,ds,target-candidates[i],i+1,n);
        ds.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        //second type of recursion problem 
        //start from current position and move till end position whethere to include or not 
        //first type was pick not pick move to next next recursion call 
       vector<vector<int>>ans;
       vector<int>ds;
      int n=candidates.size();
        func(ans,candidates,ds,target,0,n);
    
        return ans;
    }
};

//codestudio
#include<bits/stdc++.h>
void func(vector<vector<int>>&ans,vector<int> &arr,vector<int>&ds,int target,int ind,int n){
	if(target==0){
		ans.push_back(ds);
		return;
	}
	for(int i=ind;i<n;i++){
		if(i!=ind && arr[i]==arr[i-1])continue;
		if(arr[i]>target)break;
		ds.push_back(arr[i]);
	    func(ans,arr,ds,target-arr[i],i+1,n);
	    ds.pop_back();
	}
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	// Write your code here.
	vector<int>ds;
	sort(arr.begin(),arr.end());
	vector<vector<int>>ans;
	func(ans,arr,ds,target,0,n);
	return ans;
}
