/*TC=O(n^2)
SC=O(1)
CODESTUDIO*/
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	// Write your code here
	vector<int>ans;
    for(int i=0;i<n;i++){
		int flag=0;
		for(int j=i+1;j<n;j++){
			if(arr[j]>arr[i]){
				flag=1;
               ans.push_back(arr[j]);
			   break;
			}
		}
		if(flag==0)
		ans.push_back(-1);
	}
	return ans;
}


///using stack 

#include<bits/stdc++.h>
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	// Write your code here
	vector<int>v(n);
	stack<int>s;
	for(int i=n-1;i>=0;i--){
		while(!s.empty() && s.top()<=arr[i]){
			s.pop();
		}
		int res=(s.empty())?-1:(s.top());
		s.push(arr[i]);
		v[i]=res;
		
	}
	return v;
}


















/*LEETCODE BRUTE FORCE */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       vector<int>ans;
      
       for(int i=0;i<nums1.size();i++){
           int flag=0;int flageq=0;
             for(int j=0;j<nums2.size();j++){
                 if(nums2[j]==nums1[i])
                   flageq=1;
                 if(flageq==1 && nums2[j]>nums1[i]){
                     ans.push_back(nums2[j]);
                     flag=1;
                     break;
                 }
             }
                
            if(flag==0)
            ans.push_back(-1);
  }




        return ans;
    }
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
     //using stack
     stack<int>st;
    vector<int>ans;
     unordered_map<int,int>mp;
     int n=nums2.size();
     for(int i=n-1;i>=0;i--){
         while(!st.empty() && st.top()<nums2[i]){
             st.pop();
         }
         int res=(st.empty())?-1:st.top();
          mp[nums2[i]]=res;
          st.push(nums2[i]);
     }   
     for(int i=0;i<nums1.size();i++){
      ans.push_back(mp[nums1[i]]);
     }
     return ans;
    }
};
