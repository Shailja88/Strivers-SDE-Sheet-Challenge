/*TC=O(n)
  SC=O(1);
*/

#include<bits/stdc++.h>
int createAtoi(string s) {
    // Write your code here.
    int i=0;
    int n=s.size();
    long long ans=0;
    //y kam shurwat k spaces htane k liye hai 
    bool po=false;
    bool ne=false;
    while(i<n){
         if(s[i]==' ')
         i++;
          else break;
    }
    ///check for positive and negative
    if(s[i]=='-')
    ne=true;
    if(s[i]=='+')
    po=true;
    if(ne||po)
    i++;
    while(i<n) {
      if(s[i]>='0'&& s[i]<='9')
      {
         ans=ans*10+int(s[i]-'0');
         if(ans>=2147483647 &&  ne==true)return -2147483648;
         else if(ans>=2147483647 && ne==false)return 2147483647;
          i++;
      }
      else
      break;
        
    } 

  if(ne==true)return -1*ans;
    return ans;
}
