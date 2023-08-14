//brute force

#include<bits/stdc++.h>
#include<string.h>
bool isPalinrome(string r){
    string x=r;
reverse(r.begin(),r.end());
int res = x.compare(r);
   if (res==0)return true;
     return false;
}
string longestPalinSubstring(string str) {
    //check for every substring

    vector<string>a;
  for(int i=0;i<str.size();i++){
    for(int j=i;j<str.size();j++){
        string s=str.substr(i,j-i+1);
         if(isPalinrome(s))
           {
               a.push_back(s);
           }
     }
     }
 string ans=a[0];
 for(int i=0;i<a.size();i++){
      if(ans.size()<a[i].size())
      ans=a[i];
}

return ans;
}

#include<bits/stdc++.h>
string longestPalinSubstring(string str) {
    /*
    There are two cases
    we traverse all characters making present character as middle one 
    making two pointer l and r
    1 l travel left of the string 
    2.r travel right of the string 
    until the str[l]== str[r];
    if not 
    3. check whether r-l-1 >maxlen
    if yes
    {
        maxlen=r-l-1;
        and
        st=l+1;
        end=r-1;
    }
    repeat 
    return str.substr(st,maxlen);
    CASE 1: ODD length string
        l and r start with the same place 
    CASE 2:EVEN length string
        l=i and r=i+1;
        means 
        (r-l)=1;



        TC=O(n^2)
        SC=O(1)
        */
        if(str.size()<=1)return str;
        int st=0,end=0;
        int maxlen=1;
        int n=str.size();
 
      for(int i=0;i<n-1;++i){
             int l=i;
             int r=i;
          
       while(l>=0 && r<n){
               if(str[l]==str[r]){
                   r++;
                   l--;
               }
               else 
               break;
           }
         int len=r-l-1;
         if(len>maxlen){
             maxlen=len;
             st=l+1;
             end=r-1;
         }
 }  
//for even

   for(int i=0;i<n-1;++i){
             int l=i;
             int r=i+1;
          
      while(l>=0 && r<n){
               if(str[l]==str[r]){
                   r++;
                   l--;
               }
               else 
               break;
           }
         int len=r-l-1;
         if(len>maxlen){
             maxlen=len;
             st=l+1;
             end=r-1;
         }
 }  
return str.substr(st,maxlen);
        
}
