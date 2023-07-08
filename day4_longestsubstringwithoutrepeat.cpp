/*BRUTE FORCE ME 
GENERATE ALL THE POSSIBLE SUBSTRINGS
2. BETTER ME
USE SET TC=O(2N)  SC-O(1) 
3. USE MAP IN OPTIMAL SOLUTION  TC=O(N) SC=O(1)
constant size contains only 256 value ascii
*/
/*BRUTE FORCE
TC=O(n^2)
SC=O(n)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int cnt=0;
        int ans=0;
        if(n==0 || n==1)return n;
        for(int i=0;i<n;i++){
            unordered_set<int>st;
             cnt=0;
            for(int j=i;j<n;j++){
              if(st.find(s[j])==st.end()){
                  cnt++;
                  st.insert(s[j]);
              }
              else {
                  break;
              }
            }
             ans=max(cnt,ans);
        }
        return ans;
    }
};
/*BETTER APPROACH
TC=O(2n);
SC=O(n)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,l=0,r=0;
        set<int>st;
      for(int i=0;i<s.size();i++){
            while(st.find(s[i])!=st.end() && l<=r){
                      st.erase(s[l]);
                      l++;
                  }
             ans=max(ans,r-l+1);
             st.insert(s[i]);
             r++;
        }
        return ans;
    }
};

/*OPTIMAL SOLUTION 
TC=O(n)
SC=O(n)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mpp(256,-1);
        int l=0,r=0;
        int n=s.size();
        int len=0;
        while(r<n){
            if(mpp[s[r]]!=-1)l=max(mpp[s[r]]+1,l);
            mpp[s[r]]=r;
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};
