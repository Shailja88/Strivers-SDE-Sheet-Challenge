#include<bits/stdc++.h>
bool isValid(int n,int m,int i,int j,vector<vector<int>>& grid){
if(i>=0 && j>=0 && i<n && j<m && grid[i][j]==1)return true;
   return false;
}


int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    int time=0;
    queue<pair<int,int>>q;
    int track1=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }
            else if(grid[i][j]==1)
            {
                track1++;
            }
        }
    }
    if(track1==0)return 0;

    //checking after bfs traversal 
      while(!q.empty()){
            int size1=q.size();
            int temp=0;//checking that any fresh oranges is rotten or not if yes then time++ 
           while(size1){     
              pair<int,int>p=q.front();
              q.pop();
               int ax[4]={1,-1,0,0};
               int ay[4]={0,0,1,-1};
               for(int i=0;i<4;i++){
                   int x=ax[i]+p.first;
                   int y=ay[i]+p.second;
                   if(isValid(n,m,x,y,grid)){
                        grid[x][y]=2;
                        q.push({x,y});
                        temp++;

                    }
               } 
             size1--;
            }
            if(temp!=0)time++;

 }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1)
            return -1;
        }
    }


return time;
}
