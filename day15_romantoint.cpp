#include<bits/stdc++.h>
int romanToInt(string s) {
    // Brute force
    int n=s.size();
    map<char,int>m;
    m['I']=1;
    m['V']=5;
    m['X']=10;
    m['L']=50;
    m['C']=100;
    m['D']=500;
    m['M']=1000;
    int ans=0;
       for(int i=0;i<n-1;i++){
          if((s[i]=='I'&&s[i+1]=='V')||(s[i]=='I'&&s[i+1]=='X')||(s[i]=='X'&&s[i+1]=='L')||(s[i]=='C'&&s[i+1]=='M')||(s[i]=='C'&&s[i+1]=='D')||(s[i]=='X'&&s[i+1]=='C')){
              ans-=m[s[i]];
                 }
          else{
              ans+=m[s[i]];
          }
 }

 ans+=m[s[n-1]];
return ans;
}
