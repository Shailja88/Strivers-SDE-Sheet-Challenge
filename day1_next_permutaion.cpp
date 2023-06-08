//codestudio
#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &A, int n)
{
    //  Write your code here.
    int ind=-1;
    
    for(int i=n-2;i>=0;i--){
        if(A[i]<A[i+1]){
            ind=i;
            break;
        }
    }
    if(ind==-1){
        reverse(A.begin(),A.end());
        return A;
    }
    for(int i=n-1;i>ind;i--){
        if(A[i]>A[ind]){
            swap(A[i],A[ind]);
            break;
        }

    }
    reverse(A.begin()+ind+1,A.end());
    return A;
}

//leetcode
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int x=nums.size();
        int mark=-1;
        for(int i=x-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
             mark=i;
             break;
            }
        }
        if(mark==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=x-1;i>mark;i--){
            if(nums[i] > nums[mark]){
                int temp=nums[i];
                nums[i]=nums[mark];
                nums[mark]=temp;
                break;
            }
        }
        
        reverse(nums.begin()+mark+1,nums.end());
        return;
    }
};
