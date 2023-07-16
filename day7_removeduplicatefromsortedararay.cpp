/*TC=O(NlogN)+O(N);
  SC=O(N)
  */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //method 1
        set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        nums.clear();
        for(auto in : st){
            nums.push_back(in);
        }
        return nums.size();
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //two pointer approach
        /*TC=O(n)
        SC=O(1)
        */
        int i=0;
        for(int j=1;j<nums.size();j++){
           if(nums[i]!=nums[j]){
               nums[i+1]=nums[j];
               i++;
           }
        }
        return ++i;
    }
};
