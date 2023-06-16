
//brute force 
/* tc=o(n^2)
sc=o(n^2)
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>v;
    
        for(int i=0;i<n;i++){
                vector<int>temp;
            for(int j=0;j<n;j++){
            temp.push_back(matrix[n-1-j][i]);
            }
            v.push_back(temp);
        }
        matrix.clear();
        matrix=v;
    }
};

//optimal approach
//TC=O(N*N/4)+O((N^2)/2);
//SC=O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++){
       reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

//codestudio
#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int k=min(n,m);
    for(int i=0;i<k/2;i++){
       int left=i,top=i,right=m-1-i,bottom=n-i-1;
       int x=mat[left][top];
       for(int j=left+1;j<=right;j++){
           swap(x,mat[i][j]);
       }    
       for(int j=top+1;j<=bottom;j++){
           swap(x,mat[j][right]);
       }
       for(int j=right-1;j>=top;j--){
           swap(x,mat[bottom][j]);
       }
       for(int j=bottom-1;j>=top;j--){
           swap(x,mat[j][i]);
       }
    }

}
