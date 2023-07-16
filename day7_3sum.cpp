/*TC=O(n^3)
  SC=O(n)
  time limit exceeds
  */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>st;
        for(int i=0;i<n;i++)
       {
         for(int j=i+1;j<n;j++){
             for(int k=j+1;k<n;k++){
                 if(nums[i]+nums[j]+nums[k]==0){
                   vector<int>temp={nums[i],nums[j],nums[k]};  
                   sort(temp.begin(),temp.end());
                   st.insert(temp);
                 }
             }
         }
        } 
     vector<vector<int>>ans(st.begin(),st.end());
     return ans;
       }
};

/*****reduce to O(n^2*log(M)) TITME complexity******
SIZE OF THE  SET IS VARING
SC=O(n)*O(number of unique triplet *2)
*/
#include<bits/stdc++.h>
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.
    set<vector<int>>st;
    for(int i=0;i<n;i++){
       set<int>s;
      for(int j=i+1;j<n;j++){
       
         int third=-(arr[i]+arr[j]);
         if(s.find(third)!=s.end()){
           vector<int>temp={arr[i],arr[j],third};
           sort(temp.begin(),temp.end());
           st.insert(temp);
         }
         s.insert(arr[j]);
      }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
    
}



/******************* most optimal approach****************************
  TC=O(nlogn)+O(n^2)
  SC=O(no of unique triplet )
1. sort kro
2 teen pointer bnao I,j,k aur unse khelo
[-2 -2 -2 -1 -1  -1 0 0 0 2 2 2 2 ]
  *********/
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
      if(i!=0 && arr[i]==arr[i-1])continue;
      int j=i+1;
      int k=n-1;
      while(j<k){
        int sum=arr[i]+arr[j]+arr[k];
        if(sum<0){
          j++;
        }
        else if(sum>0){
          k--;
        }
        else{
          vector<int>temp={arr[i],arr[j],arr[k]};
          ans.push_back(temp);
          j++;
          k--;
          while(j<k && arr[j]==arr[j-1])j++;
          while(j<k && arr[k]==arr[k+1])k--;
          
          
        }
      }
      
    }
    return ans;
}

