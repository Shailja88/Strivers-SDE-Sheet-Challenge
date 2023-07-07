/*BRUTE FORCE 
  TC=O(n^4logn)
  SC=O(no of quadrant form)
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
     
       set<vector<int>>st;
       sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size();i++){
           for(int j=i+1;j<nums.size();j++){
               for(int k=j+1;k<nums.size();k++){
                   for(int l=k+1;l<nums.size();l++){
                       long long x= (long long)( (long long)nums[i]+ (long long)nums[j]+ (long long)nums[k]+ (long long)nums[l]);
                       if(x==(long long)target){
                           vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                           st.insert(temp);
                       }
                   }
               }
           }
       }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
    }
};
/*******************************************************************************************************************************************************************************************
[1,2,-1,-2,2,0,-1]
 1.i j k             3 pointers
 2.fourth number khojo set me agr mil gya to set<vector<int>>st m sort krke add krte chlo 
 sath me ..
 3.nums[k] ko set m daltee chlo (k ko move krna hai)
 4. jo ans aaya hai usko ans 2d vector m dal k return kr do
 TC=O(n^3logm) //m variable
 SC=O(n) + O(2*no of quads) //hashset+(ans+storing in set vector)
 
 
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>>st;
          for(int i=0;i<n;i++){
              for(int j=i+1;j<n;j++){
                  set<long long>s;
                  for(int k=j+1;k<n;k++){
                      long long sum=nums[i]+nums[j];
                      sum+=nums[k];
                      long long fourth=target-sum;
                      if(s.find(fourth)!=s.end()){
                        vector<int>temp={nums[i],nums[j],nums[k],(int)fourth};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                      }
                   s.insert(nums[k]);
                  }
              }
          }
          vector<vector<int>>ans(st.begin(),st.end());
          return ans;
    }
};


/*****************************
OPTIMAL SOLUTION 
TC=O(n^3)
SC=O(no of quads)
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         int n=nums.size();
       vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
       
        for(int i=0;i<n;i++){
            if(i>0 &&  nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n;j++){
                if(j!=(i+1) && nums[j]==nums[j-1])continue;
                int k=j+1;
                int l=n-1;
                while(k<l){
                long long sum=nums[i];
                sum+=nums[j];
                sum+=nums[k];
                sum+=nums[l];
                if(sum==target){
                    vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                   ans.push_back(temp);
                   k++;
                   l--;
                   while(k<l && nums[k]==nums[k-1])k++;
                   while(k<l &&  nums[l]==nums[l+1])l--;
                }
               else if(sum<target){
                  k++;
                }
                else{
                l--;
                }
            }
            }
        }
      
        return ans;
    }
};
