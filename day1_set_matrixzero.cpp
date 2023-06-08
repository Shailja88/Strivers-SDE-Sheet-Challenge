//codestudio
#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
 int rows=matrix.size();
 int col=matrix[0].size();
  int col0=1;
  for(int i=0;i<rows;i++){
    if(matrix[i][0]==0)col0=0;
    for(int j=1;j<col;j++){
      if(matrix[i][j]==0)
      {
        matrix[i][0]=0;
        matrix[0][j]=0;
      }
    }
  }
  for(int i=rows-1;i>=0;i--){
    for(int j=col-1;j>0;j--){
 
     if(matrix[i][0]==0||matrix[0][j]==0)
        matrix[i][j]=0;
    
    }
  }if(col0==0){
     for(int i=rows-1;i>=0;i--){
    matrix[i][0]=0;
  }
  }
 
}


//leetcode
//time complexity =O(2*x*y)
//space complexity =O(x)+O(y)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int x=matrix.size();
        int y=matrix[0].size();
        int row[300]={0};
        int column[300]={0};
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(matrix[i][j]==0){
                    row[i]=-1;
                    column[j]=-1;
                }
            }
        }
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(row[i]==-1 || column[j]==-1){
                    matrix[i][j]=0;
                }
            }
        }
    }
};



