//codestudio
vector<int> search(string s, string pattern) {
   //brute force
   vector<int>v;
   int size=pattern.size();
   string str=pattern+"#"+s;
    int n=str.size();
    vector<int>z(n,0);
 for(int i=1;i<n;i++){
     int j=0;int r=i;
     int cnt=0;
     while(j<n && str[j]==str[r]){
         cnt++;
         r++;
         j++;
     }
     z[i]=cnt;

 }
 for(int i=0;i<z.size();i++){
    if(z[i]==size)
    v.push_back(i-size);

    
}
return v;
}
//leetcode
int strStr(string s1, string s2) {
       int l=s1.size();
      int l2=s2.size();
   for(int i=0;i<(l-l2+1);i++){
       if(s1.substr(i,l2)==s2)
       return i;
   }
   return -1;}
};

// TC=O(n+m) SC=O(n+m)
#include<bits/stdc++.h>
vector<int> search(string s, string pattern) {
    // Write Your Code Here
    int slen=s.length();
    int plen=pattern.length();
    vector<int>ans;
    string new_str=pattern+"#"+s;///forming new string
    vector<int>z;
    int i=0;
    while(i<new_str.length()){
          if(i<=plen){
              z.push_back(0);
          }
          else{
              int l=0;
              int r=0;
              if(new_str[l]==new_str[i]){
                  r=i;
                  while(r<new_str.length() && new_str[l]==new_str[r]){
                      l++;r++;
                  }
                  
              }
              z.push_back(l);
          }
          i++;
    }
    


 for(int i=0;i<z.size();i++){
     if(z[i]==plen)
     ans.push_back(i-plen);
 }
  return ans;
}
