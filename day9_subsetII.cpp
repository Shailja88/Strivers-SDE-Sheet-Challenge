/*recursion 
TC=O(2^n*n)+O(nlogn)
SC=O(2^n)*O(k)
AUXILLIARY SPACE TC=O(n);
*/
#include <bits/stdc++.h> 
void func(vector<vector<int>>&ans,vector<int>&v,vector<int>&arr,
int n,int ind){
        ans.push_back(v);
        for(int i=ind;i<n;i++){
            if(i!=ind && arr[i]==arr[i-1])continue;
            v.push_back(arr[i]);
          
            func(ans,v,arr,n,i+1);
           v.pop_back();
        }
       
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>>ans;
    vector<int>v;
    sort(arr.begin(),arr.end());
    func(ans,v,arr,n,0);
    return ans;
}
