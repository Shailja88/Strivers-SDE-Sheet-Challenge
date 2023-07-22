//method 1
int median(vector<vector<int>> &matrix, int m, int n) {
    // Write your code here.
    vector<int>v;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            v.push_back(matrix[i][j]);
        }
    }
    sort(v.begin(),v.end());
    int x=v.size();
    int r=x/2;
    return v[r];
}

//method 2
#include<bits/stdc++.h>
/*TC=O(32 mlogn)
SC=O(1)*/
int countSmallerandEqualtoMid(vector<int>&a,int r){
    int l=0,h=a.size()-1;
    while(l<=h){
        int m=(l+h)>>1;
        if(a[m]<=r){
            l=m+1;
        }
        else h=m-1;
    }
    return l;
}
int median(vector<vector<int>> &matrix, int m, int n) {
    // Write your code here.
    int low=1;
    int high=1e9;
while(low<=high){
    int mid=(low+high)>>1;
        int cnt=0;
        for(int i=0;i<m;i++){
            cnt+=countSmallerandEqualtoMid(matrix[i],mid);
        }
        if(cnt<=(m*n)/2)low=mid+1;
        else high=mid-1;
}
return low;
}
