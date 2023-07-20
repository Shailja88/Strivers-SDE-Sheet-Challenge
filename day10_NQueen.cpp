//codestudio
#include<bits/stdc++.h>
bool isSafe(int row,int col,vector<int>&board,int n){
    int r=row;
    int c=col;
    while(row>=0&& col>=0){
        if(board[row*n+col]==1)return false;
        row--;
        col--;
    }
   row=r;
   col=c;
   while(col>=0){
       if(board[row*n+col]==1)return false;
       col--;
   }
   row=r;
   col=c;
while(row<n&& col>=0){
    if(board[row*n+col]==1)return false;
    row++;
    col--;
}
return true;
}
void solve(vector<int>&board,int col,int n,vector<vector<int>>&ans){
          if(col==n){
              ans.push_back(board);
              return;
          }
          for(int row=0;row<n;row++){
              if(isSafe(row,col,board,n)){
                  board[row*n+col]=1;
                  solve(board,col+1,n,ans);
                  board[row*n+col]=0;
              }
          }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    int x=n*n;
    vector<int>board(x);
    for(int i=0;i<x;i++){
        board[i]=0;
    }
    vector<vector<int>>ans;
    solve(board,0,n,ans);
    return ans;
}
//optimal codestudio
#include<bits/stdc++.h>

void solve(vector<int>&board,int col,int n,vector<vector<int>>&ans,vector<int>&leftrow,vector<int>&upperdiagonal,vector<int>&lowerdiagonal){
          if(col==n){
              ans.push_back(board);
              return;
          }
          for(int row=0;row<n;row++){
              if(lowerdiagonal[row+col]==0&& upperdiagonal[n-1+col-row]==0 &&leftrow[row]==0){
                  board[row*n+col]=1;
                  lowerdiagonal[row+col]=1;
                  upperdiagonal[n-1+col-row]=1;
                  leftrow[row]=1;
                     solve(board,col+1,n,ans,leftrow,upperdiagonal,lowerdiagonal);
                     lowerdiagonal[row+col]=0;
                     upperdiagonal[n-1+col-row]=0;
                     leftrow[row]=0;
                  board[row*n+col]=0;
              }
          }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    int x=n*n;
    vector<int>board(x);
    for(int i=0;i<x;i++){
        board[i]=0;
    }
    vector<int>leftrow(n,0);
    vector<int>upperdiagonal(2*n-1,0);
    vector<int>lowerdiagonal(2*n-1,0);
    vector<vector<int>>ans;
    solve(board,0,n,ans,leftrow,upperdiagonal,lowerdiagonal);
    return ans;
}
/****************************************************************************************************/
//LEETCODE
class Solution {
public:
bool isSafe(int row,int col,vector<string>&board,int n){
    int r=row;
    int c=col;
     /*teen direction m check krna hai  
                       \
                   -----
                       /
    kyuki >=column+1  khali rhenge abhi koii queen aayi h nhi hai wha pe smjhe !
     */
   while(col>=0 && row>=0){
       if(board[row][col]=='Q')return false;
       row--;
       col--;
   }
   row=r;
   col=c;
   while(col>=0){
       if(board[row][col]=='Q')return false;;
       col--;
   }
   row=r;
   col=c;
   while(col>=0 && row<n){
       if(board[row][col]=='Q')return false;
       col--;
       row++;
   }
   return true;
}
void solve(vector<vector<string>>&ans,int n,int col,vector<string>&board){
    //base case
    if(col==n){
        ans.push_back(board);
        return ;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
           board[row][col]='Q';
           //recursion call
           solve(ans,n,col+1,board);
           board[row][col]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string>board(n);//size define  krna h pdega nhi to runtime error dega 
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<vector<string>>ans;
        //col=0;
        solve(ans,n,0,board);
        return ans;
    }
};


//optimal approach using left row ,upper diagonal and lower diagonal vector
class Solution {
public:
   /*OPTIMISE APPROACH
   teen direction m check krna hai  
                       \
                   -----
                       /
    kyuki >=column+1  khali rhenge abhi koii queen aayi h nhi hai wha pe smjhe !
     */

void solve(vector<vector<string>>&ans,int n,int col,vector<string>&board,vector<int>&upperDiagonal,vector<int>&lowerDiagonal,vector<int>leftRow){
    //base case
    if(col==n){
        ans.push_back(board);
        return ;
    }
    for(int row=0;row<n;row++){
        if(leftRow[row]==0&& lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0){
           board[row][col]='Q';
           //recursion call
           leftRow[row]=1;
           lowerDiagonal[row+col]=1;
           upperDiagonal[n-1+col-row]=1;
          solve(ans,n,col+1,board,upperDiagonal,lowerDiagonal,leftRow);
           board[row][col]='.';
            leftRow[row]=0;
           lowerDiagonal[row+col]=0;
           upperDiagonal[n-1+col-row]=0;
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string>board(n);//size define  krna h pdega nhi to runtime error dega 
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<vector<string>>ans;
        //col=0;
        vector<int>leftRow(n,0),upperDiagonal(2*n-1,0),lowerDiagonal(2*n-1,0);
        solve(ans,n,0,board,upperDiagonal,lowerDiagonal,leftRow);
        return ans;
    }
};
