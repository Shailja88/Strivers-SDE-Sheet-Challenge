//1
#include<bits/stdc++.h>
string reverseString(string &s){
	// Write your code here.	
string ans="";
string str="";
for(int i =0;i<s.size();i++){
if(s[i]!=' '){
	str=str+s[i];
}
if(s[i]==' '){
	if(str.size()==0)continue;
	else{
		ans=str+" "+ans;
		str="";
	}
}
}
if(str.size()!=0){
 ans=str+" "+ans;
}
return ans;	
}
//2
class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int n=s.size();
        string res;
        while(i<n){
            while(i<n && s[i]==' ')
            i++;
            if(i>=n)break;///man lo sare blank space hue to
            int j=i+1;
            while(j<n && s[j]!=' ')
            j++;
           string temp=s.substr(i,j-i);
           if(res.size()==0)res=temp;
           else
           res=temp+" "+res; 
           i=j+1;
 }
 return res;
    }
};
//3
string reverseString(string &str){
	// Write your code here.	

	if(str==""|| str==" ")return "";
	
   string ans;
   int start=str.length()-1;
   while(start>=0){
	   
	   if(str[start]==' ')
	   start--;
	   else{
		   if(ans.length()>0)
		   ans.push_back(' ');
		   int j=start;
		   while(j>=0 && str[j]!=' ')
		   j--;
		   ans.append(str.substr(j+1,start-j));
		   start=j;
	   }
   }
   return ans;
}






