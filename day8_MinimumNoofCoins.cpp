/*TC=O(1)
  SC=O(1)
  */
#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    int cnt=0;
    // Write your code here
    int ar[]={1000,500,100,50,20,10,5,2,1};
    for(int i=0;i<9;i++){
        cnt+=(amount/ar[i]);
        amount=amount%ar[i];
    }
    return cnt;
}
