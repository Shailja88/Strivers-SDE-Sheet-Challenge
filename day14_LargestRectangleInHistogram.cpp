/*Brute force TC=O(n^2)
SC=O(1)
Time Limit Exceeded
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        int maxArea=INT_MIN;
        for(int i=0;i<n;i++){
            int minHeight=INT_MAX;
            for(int j=i;j<n;j++){
                minHeight=min(minHeight,arr[j]);
                maxArea=max(maxArea,minHeight*(j-i+1));
            }
        }
        return maxArea;
    }
};

/* Optimal Solution
Concept used 
next smaller element
and stack
TC=O(2N)
SC=O(3N)
*/
#include<bits/stdc++.h>
 int largestRectangle(vector < int > & a) {
   // Write your code here.
   int n=a.size();
   stack<int>st;//stack for storing(push) the index in ascending order 
   vector<int>ls(n);//vector for left smallest 
   vector<int>rs(n);//vector for right smallest
   
   for(int i=0;i<n;i++){
     while(!st.empty() && a[st.top()]>=a[i]){
       st.pop();
     }
     if(st.empty()){
       ls[i]=0;
     }
     else
     ls[i]=st.top()+1;
     
     st.push(i);
   }
 st=stack<int>();//reinitializing the stack tc=O(1);
     for(int i=n-1;i>=0;i--){
     while(!st.empty() && a[st.top()]>=a[i]){
       st.pop();
     }
     if(st.empty()){
       rs[i]=n-1;
     }
     else
     rs[i]=st.top()-1;
     
     st.push(i);
   }
int ans=INT_MIN;
for(int i=0;i<n;i++){
  
  ans=max(ans,((rs[i]-ls[i]+1)*a[i]));
}

   return ans;
 }

*/
/*Best Approach
Optimal approach but with single pass
TC=O(2n)
SC=O(n)
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int ans=INT_MIN;
        for(int i=0;i<=n;i++){
              while(!st.empty()&&(i==n || heights[st.top()]>=heights[i])){
                int height=heights[st.top()];
                st.pop();
                int width;
                 if(st.empty())
                 width=i;
                 else
                 width=i-st.top()-1;
               ans=max(ans,(height*width));
             }
            st.push(i);
      }
      return ans;
    }
};


  
