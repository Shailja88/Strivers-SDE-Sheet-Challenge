/*DP====MEMOIZATION 
TC=O(m*n)
SC=O(n*m)
*/

class Solution {
public:
    int countPaths(int i,int j,int n,int m,vector<vector<int>> &dp)
    {
        if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
     else return dp[i][j]=countPaths(i+1,j,n,m,dp)+countPaths(i,j+1,n,m,dp);
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
       
        //dp[1][1]=1;
       int num=countPaths(0,0,m,n,dp);
        if(m==1&&n==1)
            return num;
        return dp[0][0];
    }
};
/*optimal solution
TC=O(n+m)
SC=O(1)
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        int ans=1;
        int r=m+n-2;
        int x=min(m,n);
        if(m>r || n>r)return 1;
        for(int i=1;i<x;i++){
            ans=(ans*(r--))/i;
    }
    return ans;
    }
};
