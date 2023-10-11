#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &image, int row,int col,int newColor, int x, int y,int s ){
     if(x<0 || y<0 || x>=row|| y>=col || image[x][y]!=s || image[x][y]==newColor)
     return ;
     image[x][y]=newColor;
     dfs(image,row,col,newColor,x-1,y,s);
     dfs(image,row,col,newColor,x,y-1,s);
     dfs(image,row,col,newColor,x+1,y,s);
     dfs(image,row,col,newColor,x,y+1,s);

}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    int row=image.size();
    int col=image[0].size();
    int s=image[x][y];
    dfs(image,row,col,newColor,x,y,s);
    return image;
}
