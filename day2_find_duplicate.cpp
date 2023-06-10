

/* method 1:
Time complexity=O(nlogn +n);
Space Complexity=O(1)
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //constant space + without modifying
        int x=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<x-1;i++){
            if(nums[i]==nums[i+1])
            return nums[i];
        }
return -1;
    }
};
/*************************************************************************************************************************************************************/
/*method 2: 
space complexity=O(n);
time complexity=O(n);
**using array 
**using  set;
*/

///USING ARRAY AS EXTRA SPACE 
#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
  int ar[n] = {0};
  for (int i = 0;i<n;i++){
	  ar[arr[i]]++;
  }
  for (int i = 0; i < n; i++) {
    if (ar[i] > 1)
      return i;
  }
  return -1;
}

///USING SET AS EXTRA SPACE 
#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n) {
  // Write your code here.
  unordered_set<int> s;
  for (int i = 0; i < n; i++)
{
	if(s.find(arr[i])==s.end())
	s.insert(arr[i]);
	else
	return arr[i];
}
return -1;
}
/*************************************************************************************************************************************************************/
/* Optimal Apporach
Space complexity =O(1)
Time complexity=O(n);
*/

/*
LINKED LIST CYCLE METHOD

TORTOISE METHOD 
*/
