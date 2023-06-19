//LEETCODE 

/*  Brute Force Approach
TC-O(2n+n(logn)
    SC-O(n)
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //brute force
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
       for(int i=0;i<n;i++){
           int start=intervals[i][0];
           int end=intervals[i][1];
           if(!ans.empty() && end<=ans.back()[1]){
               continue;
           }
           for(int j=i+1;j<n;j++){
               if(intervals[j][0]<=end){
                   end=max(end,intervals[j][1]);
               }
               else{
                    break;
               }
           }
           ans.push_back({start,end});
       }


   return ans;
    }
};


/*Optimal Approach
TC-O(n(logn)+n)
SC-O(n)
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
  vector<vector<int>>ans;
        int n=intervals.size();
         sort(intervals.begin(),intervals.end());
       for(int i=0;i<n;i++){
       if(!ans.empty() && intervals[i][0]<=ans.back()[1]){
        ans.back()[1]=max(intervals[i][1],ans.back()[1]);
         }
         else
         ans.push_back(intervals[i]);
       }
       return ans;
    }
};


//CODESTUDIO


//Brute force approach

#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sort(intervals.begin(),intervals.end());
    int n=intervals.size();
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
    int start=intervals[i][0];
    int end=intervals[i][1];
      if(!ans.empty() && end<=ans.back()[1]){
          continue;
      }
      for(int j=i+1;j<n;j++){
          if(intervals[j][0]<=end){
              end=max(end,intervals[j][1]);
          }
          else {
              break;
          }
      }
      ans.push_back({start,end});
    }
    return ans;

}


///optimal approach 
#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{      vector<vector<int>>ans;
        int n=intervals.size();
         sort(intervals.begin(),intervals.end());
       for(int i=0;i<n;i++){
       if(!ans.empty() && intervals[i][0]<=ans.back()[1]){
        ans.back()[1]=max(intervals[i][1],ans.back()[1]);
         }
         else
         ans.push_back(intervals[i]);
       }
       return ans;
}
