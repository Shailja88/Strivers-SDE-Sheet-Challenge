//codestudio
#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long>>v;
  for(int i=0;i<n;i++){
    vector<long long>temp;
    for(int j=0;j<=i;j++){
      if(j==0||i==j)
 temp.push_back(1);

      else {
        temp.push_back(v[i - 1][j - 1] + v[i - 1][j]);
      }
    }
    v.push_back(temp);
  }

  return v;
}

//leetcode

class Solution {
public:
vector<int>row(int n){
    long long anss=1;
    vector<int>ans;
   
    ans.push_back(1);
    for(int i=1;i<n;i++){
     anss=(anss*(n-i))/i;
     ans.push_back(anss);
    }
    return ans;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(row(i));
        }
        return ans;
    }
};
