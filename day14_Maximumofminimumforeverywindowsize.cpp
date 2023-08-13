//Brute force 
#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    int k=n;
    vector<int>ans;
    for(int i=0;i<n;i++)
    {   vector<int>temp;
      for(int j=0;j<=i;j++){
      
        int mn=INT_MAX;
          for(int r=j;r<k+j;r++){
          mn=min(mn,a[r]);
           }
           temp.push_back(mn);
       }
       int mx=INT_MIN;
       for(int m=0;m<temp.size();m++){
         mx=max(mx,temp[m]);
       }
       ans.push_back(mx);
      k--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

//optimall
#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    vector<int>res(n,INT_MIN);
    stack<int>s;
    a.push_back(INT_MIN);
    for(int i=0;i<=n;i++){
      while(!s.empty() && a[s.top()]>=a[i]){
        int top=a[s.top()];
        s.pop();
        int small_left=s.empty()?-1:s.top();
        int range=i-small_left-1;
        if(res[range-1]<top)
        res[range-1]=top;
        
      }
      s.push(i);
    }
    int max=INT_MIN;
    for(int i=res.size()-1;i>-1;i--){
      if(res[i]>max)max=res[i];
      res[i]=max;
    }
    return res;
}
