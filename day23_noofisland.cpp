#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&arr,int n,int m,int i,int j,int delcol[],int delrow[]){
   arr[i][j]=0;

for(int k=0;k<8;k++){
   int r=i+delrow[k];
   int c=j+delcol[k];
   if(r>=0 && c>=0 && r<n && c<m && arr[r][c]==1){
      dfs(arr,n,m,r,c,delcol,delrow);
   }
}


}
int getTotalIslands(int **ar, int n, int m)
{
   vector<vector<int>>arr;

   ///do dfs and return count;
   int delrow[8]={-1,-1,0,1,1,1,0,-1};

   int delcol[8]={0,1,1,1,0,-1,-1,-1};
  for(int i=0;i<n;i++)
{
   vector<int>temp;
   for(int j=0;j<m;j++){
temp.push_back(ar[i][j]);
   }
   arr.push_back(temp);
}

  
    int cnt=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(arr[i][j]==1){
          cnt++;
         dfs(arr,n,m,i,j,delcol,delrow);

          }
}
     }
     return cnt;
}
