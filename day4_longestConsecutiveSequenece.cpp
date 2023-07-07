/*Brute force
TC=O(n^3)
SC=O(1)
*/
#include <bits/stdc++.h>
bool ls(vector<int>&arr,int x){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==x)return true;
    }
    return false;
}
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    
    int longest=1;
    for(int i=0;i<n;i++){
        int x=arr[i]+1;
        int cnt=1;
        while(ls(arr,x)==true){
            cnt=cnt+1;
            x=x+1;
        }
        longest=max(longest,cnt);
    }
    return longest;
}
/**********************************************************************************/
/*distorting the size and position of the array
TC=O(nlogn +n+n)
SC=O(n)
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
        int x=nums.size();
        if(x==0)return 0;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        nums.clear();
        for(auto in : s){
            nums.push_back(in);
        }
        int ans=INT_MIN;
        int cnt=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]-1)cnt=cnt+1;
            else{
             ans=max(ans,cnt);
             cnt=1;
            }
        }
     return max(ans,cnt);
       
    }
};

/*
BETTER SOLUTION
distorting  the array
[1 1 1 2 2 2 3 3 4 100 101 102]
TC=O(nlogn + n)
SC=O(1)
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==0)return 0;
        int longest=1;
        int cnt=0;
        int lastSmaller=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]-1==lastSmaller){
                cnt++;
                lastSmaller=nums[i];
            }
            else if(nums[i]!=lastSmaller){
                cnt=1;
                lastSmaller=nums[i];
            }
            longest=max(longest,cnt);
        }
return longest;
    }
};

/*OPTITMAL SOLUTION 
TC=O(n)+O(2n) =O(n)//assumption that set is taking O(1) tc
SC=O(n)
*/
#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    if(n==0)return 0;
    int longest=1;
    unordered_set<int>st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    for(auto in : st){
        if(st.find(in-1)==st.end()){
            int cnt=1;
            int x=in;
            while(st.find(x+1)!=st.end()){
                cnt+=1;
                x=x+1;
            }
            longest=max(longest,cnt);
            
        }
        
    }
    return longest;
}
