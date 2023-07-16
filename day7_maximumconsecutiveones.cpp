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

