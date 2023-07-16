/*TC=O(n)
  SC=O(1)
  */
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int cnt=1,ans=1,mainans=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]&& nums[i]!=0){
                ans++;
            }
            else if(nums[0]==0 &&nums[i]==0){
                 cnt++;
            }
            else{
               mainans=max(mainans,ans);
                ans=1;
            }
        }
        if(cnt==nums.size()&& nums[0]==0)return 0;
        return max(mainans,ans);
    }

};
/*TC=O(n)
SC=O(1)
*/

  

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
               if(nums[i]==1){
                   cnt++;
                  ans=max(cnt,ans);
               }
               else
                   cnt=0;
                }
               return ans;  
  }
};

/*codestudio
partially accepted
calculating all subarrays 
TC=O(N^2)
SC=O(1)
*/
#include<bits/stdc++.h>
int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int ans=0;
    int x;
    for(int i=0;i<n;i++){
        int cnt=0;
        x=k;
    for(int j=i;j<n;j++){
        if(arr[j]==1){
            cnt++;
            ans=max(cnt,ans);
        }
        else if(arr[j]==0 && x>0){
            cnt++;
            ans=max(cnt,ans);
            x--;
        }
        else if(arr[j]==0&& x<=0){
            break;
        }
}
ans=max(cnt,ans);

}
return ans;
}



/*TWO POINTER OF SLIDING WINDOW APPROACH*/
int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int cnt_0=0;
    int l=0;
    int maxlen=0;
   
    for(int r=0;r<n;r++){
        if(arr[r]==0){
            cnt_0++;
        }
        while(cnt_0>k){
            if(arr[l]==0){
                cnt_0--;
            }
            l++;
        }
        maxlen=max(maxlen,r-l+1);
    }
    return maxlen;
}
