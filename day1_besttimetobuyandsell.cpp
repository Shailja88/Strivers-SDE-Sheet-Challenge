//codestudio
#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int mini=INT_MAX;
    int profit=0;
    for(int i=0;i<prices.size();i++){
        mini=min(mini,prices[i]);
        profit=max(profit,(prices[i]-mini));
    }
    return profit;
}

//leetocode
class Solution {
public:
    int maxProfit(vector<int>& prices) {
     //auxillary space
     int x=prices.size();
     int maxi=INT_MIN;
     int ans=INT_MIN;
     int arr[x];
     for(int i=x-1;i>=0;i--){
          maxi=max(prices[i],maxi);
         arr[i]=maxi;
     } 
     for(int i=0;i<x;i++){
        ans=max(ans,(arr[i]-prices[i]));
     }  
     return ans;
    }
};
