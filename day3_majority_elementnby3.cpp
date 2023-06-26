//majority element n/3 times 
/*There can be atmost 2 elements which will appear n/3 times =======dimag lgao kyu revise krte wkt apne ok!!
100/3~ 33 so 34 +34 +34 =102>100 not possible hence 34 + 34 can be the  only way hence element are 2 
..........................................................................................................................................
Brute force to O(n*n)

..................................................................................................................................
NOTE: using sort() function --->distorting the arrayy! not recommended 

................................................................................................................
 OPTIMAL APPROACH 
  SC=O(n)
  TC=O(2n);

...................................................................................................
  */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int n=nums.size();
        for(auto in : mp){
            if(in.second>(n/3)){
                ans.push_back(in.first);
            }
        }
        return ans;
    }
};

/*Moore's voting algorithm 
TC=O(2n)
SC=O(1)
  */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>v;
        int n=nums.size();
        int cnt1=0,cnt2=0;
        int ele1,ele2;
        for(int i=0;i<n;i++){
            if(cnt1==0  && nums[i]!=ele2){
                cnt1++; 
                ele1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=ele1){
                cnt2++;
                ele2=nums[i];
            }
            else if(ele1==nums[i]){
                cnt1++;
            }
            else if(ele2==nums[i]){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;cnt2=0;
        for(int i=0;i<n;i++){
             if(nums[i]==ele1)cnt1++;
             if(nums[i]==ele2)cnt2++;
        }
        if(cnt1>(n/3))v.push_back(ele1);
        if(cnt2>(n/3))v.push_back(ele2);
      return v;
        
    }
};
  
