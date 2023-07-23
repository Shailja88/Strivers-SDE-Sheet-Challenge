/*brute force time limit  exceeded*/
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    vector<int>ans;
    for(int i=0;i<m;i++){
         ans.push_back(row1[i]);
    }
    for(int i=0;i<n;i++){
            ans.push_back(row2[i]);
    }
    sort(ans.begin(),ans.end());
    return ans[k-1];
}
//method 2
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    int cnt=0;
    
    int i=0;
    int j=0;
   if(k==1)return min(row1[0],row2[0]);
    while(j!=n && i!=m){
       if(row1[i]>row2[j]){
           j++;
           cnt++;
           if(k==cnt)return row2[j-1];
       }
       else {
           i++;
           cnt++;
           if(k==cnt)return row1[i-1];
       }
    }
    while(j!=n){
         j++;
           cnt++;
           if(k==cnt)return row2[j-1];
    }
    while(i!=m){
         i++;
           cnt++;
           if(k==cnt)return row1[i-1];
    }
    return -1;
}

//method 3 TC=O(min(log n, log m))  SC=O(1)
#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &arr1, vector<int> &arr2, int m, int n, int k) {
    // Write your code here.
    if(arr1.size()>arr2.size()){
        return ninjaAndLadoos(arr2,arr1,n,m,k);
    }
   int low=max(0,k-n);
   int high=min(m,k);
   while(low<=high){
    int cut1=(low+high)/2;
    int cut2=k-cut1;
    int l1=(cut1!=0)?arr1[cut1-1]:INT_MIN;
    int l2=(cut2!=0)?arr2[cut2-1]:INT_MIN;
    int r1=(cut1!=m)?arr1[cut1]:INT_MAX;
    int r2=(cut2!=n)?arr2[cut2]:INT_MAX;
    if(l1<=r2 && l2<=r1)
    return max(l1,l2);
    if(l1>r2){
        high=cut1-1;
    }
    else{
        //l2>r1
        low=cut1+1;
    }
   }
   return -1;
}
    
    








       
   









    

