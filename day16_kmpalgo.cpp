//sliding window
class Solution {
public:
    int strStr(string haystack, string needle) {
      //sliding  window
        int n=haystack.length();
        int m=needle.length();
        int  r=0;
        for(int i=0;i<n;i++){
            if(haystack[i]==needle[r]){
                r++;
            }
            else{
                i=i-r;
                r=0;
            }
            if(r==m)return i-m+1;
        }
        return -1;
    }
};

//z algo
class Solution {
public:
    int strStr(string s, string p) {
        int slen=s.size();
        int plen=p.size();
        string newstr=p+"#"+s;
        int i=plen+1;
        while(i<newstr.size()){
           int l=0;
           int r=0;
           if(newstr[i]==newstr[l]){
               r=i;
               while(newstr[l]==newstr[r]){
                   l++;
                   r++;
               }
           }  
          if(l==plen)
             return i-plen-1;
             i++;
        }
       return -1;
    }
};

//kmp algo
#include<bits/stdc++.h>
void fillLPS(string pattern,vector<int>&lps){
	int n=pattern.size();
	int len=0;
	int i=1;
	lps[0]=0;
	while(i<n){
		if(pattern[i]==pattern[len]){
			len++;
			lps[i]=len;
			i++;
		}
		else{
			if(len==0)
		{	lps[i]=0;
		i++;
		}
		else{
			len=lps[len-1];
		}
		}
	}
	return;
}
vector<int> stringMatch(string text, string pattern) {
	// Write your code here.
	vector<int>ans;
	int n=text.size();
	int m=pattern.size();
	vector<int>lps(m);
	fillLPS(pattern,lps);
	int i=0,j=0;
	while(i<n){
		if(text[i]==pattern[j]){ 
			i++;j++;
			if(j==m){
				ans.push_back((i-j+1));
				j=lps[j-1];
			}
		}
		else if(i<n && text[i]!=pattern[j]){
			if(j==0){
				i++;
			}
			else{
				j=lps[j-1];
			}
		}
	}
return ans;
}
