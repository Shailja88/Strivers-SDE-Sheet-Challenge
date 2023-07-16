/* time limit exceeded 
TC=O(n^2)
SC=O(1);
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        for(int  i=0;i<height.size();i++){
            //calculate maximum left
           int left=INT_MIN;
           int right=INT_MIN;
           for(int j=0;j<=i;j++){
            left=max(left,height[j]);
           }
            //calculate maximum right;
             for(int j=i;j<height.size();j++){
              right=max(right,height[j]);
             }
             ans+=min(right,left)-height[i];
        }
   return ans;
    }
};
/* 
prefix sum and suffix sum calculate kro 
mtlb k aage s bde ko store krke rkh do and peeche s bde ko store krke rkh do 

   TC=O(n)
  SC=O(n)
  */
class Solution {
public:
    int trap(vector<int>& height) {
        ///prefix sum and suffix sum calculate krke rkho
        int  ans=0;
        // vector<int>prefix;
        // vector<int>suffix;
        // vector<int>minii;
        int h=height.size();
                int prefix[h];
                int suffix[h];
                int minii[h];
      
        int maxi1=INT_MIN;
        int maxi2=INT_MIN;
        for(int i=0;i<height.size();i++){
            maxi1=max(maxi1,height[i]);
            prefix[i]=maxi1;
        }
        for(int i=(height.size()-1);i>=0;i--){
        maxi2=max(maxi2,height[i]);
           suffix[i]=maxi2;
        }
    for(int i=0;i<height.size();i++){
      minii[i]=min(suffix[i],prefix[i]);
    
   }
   for(int i=0;i<height.size();i++){
       int r=minii[i]-height[i];
        if(r>0){
               ans=ans+r;
        }
    
   }
return ans;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        ///two pointer approach
        /*TC=O(N)
        SC=O(1)
        */
        int  l=0;
        int r=height.size()-1;
        int lmax=0,rmax=0;
        int result=0;
        while(l<=r){
           if(height[l]<=height[r]){
             if(lmax<=height[l])
              lmax=height[l];
             else
              result=result+(lmax-height[l]);
             l++;
           }
          else{
    //height[l]>height[r];
            if(rmax<height[r])
             rmax=height[r];
            else
             result=result+(rmax-height[r]);
            r--;
             }
      }
        return result;
    }
};
