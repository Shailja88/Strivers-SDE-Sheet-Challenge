/* time complexity: O(2^n)
PalindromeI
  */
#include<bits/stdc++.h>
bool isPalindrome(string s,int initial,int end){
    while(initial<=end){
        if(s[initial++]!=s[end--]){
            return false;
        }
    }
    return true;
}

void func(vector<vector<string>>&ans,vector<string>&path,string s,int n,int ind){
    if(ind==n){
        ans.push_back(path);
        return;
    }
    for(int i=ind;i<n;++i){
    if(isPalindrome(s,ind,i)){
         path.push_back(s.substr(ind,i-ind+1));
         func(ans,path,s,n,i+1);
         path.pop_back();
         }
         }
}

vector<vector<string>> partition(string s) {
vector<vector<string>>ans;
vector<string>path;
int n=s.size();
func(ans,path,s,n,0);
return ans;
}

/*palindrome second
without memoization*/
#include <bits/stdc++.h> 
//without dp
bool isPalindrome(int i,int j,string s){
    while(i<j)
    {if(s[i++]!=s[j--])return false;
    }
    return true;
}
 int func(string &s,int ind,int n){
   if(ind==n)return 0;
   int mincost=INT_MAX;
   for(int j=ind;j<n;j++){
       if(isPalindrome(ind,j,s)){
       int cost=1+func(s,j+1,n);
        mincost=min(mincost,cost);
       }
   }
return mincost;
 }
int palindromePartitioning(string str) {
  int n=str.size();
    // Write your code here
  return func(str,0,n)-1;


}


#include <bits/stdc++.h> 
//with dp  palindrome II
bool isPalindrome(int i,int j,string s){
    while(i<j)
    {if(s[i++]!=s[j--])return false;
    }
    return true;
}
 int func(string &s,int ind,int n,vector<int>&dp){
   if(ind==n)return 0;
   if(dp[ind]!=-1)return dp[ind];
   int mincost=INT_MAX;
   for(int j=ind;j<n;j++){
       if(isPalindrome(ind,j,s)){
       int cost=1+func(s,j+1,n,dp);
        mincost=min(mincost,cost);
       }
   }
return dp[ind]=mincost;
 }
int palindromePartitioning(string str) {
  int n=str.size();
    // Write your code here
    vector<int>dp(n,-1);
  return func(str,0,n,dp)-1;


}

