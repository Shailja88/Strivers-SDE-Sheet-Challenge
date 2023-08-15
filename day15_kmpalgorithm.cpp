#include<bits/stdc++.h>
bool ischeck(int st,int en,string pattern,string text){
	int x=0;
	bool flag=true;
	
	for(int i=st;i<=en;i++){
		if(text[i]!=pattern[x]){
		    	flag=false;
		}
	
		x++;
	
	}

	return flag;
}
vector<int> stringMatch(string text, string pattern) {

	 vector<int>ans;
	 map<char,int>mp;
	 mp['a']=1;
	 for(int i=1;i<=25;i++){
		 char s=char('a'+i);
         mp[s]=i+1;//mapping 
     
	 }
	 int val=0;
	 int q=17;
	 for(int i=0;i<pattern.size();i++){
	        val=val+mp[pattern[i]];
     }
	 int r=val%q;

	  int tsize=text.size();
	  int psize=pattern.size();
	  int i=0,j=0;
	  int sum=0;
	  while(j<psize-1){
            sum+=mp[text[j]];
		    j++;
	  }
	  while(j<tsize){
		  sum=sum+mp[text[j]];
		
		  
          if(sum%q==r){
			  if(ischeck(i,j,pattern,text)==true){
				  ans.push_back(i+1);
				  
			  }
		  }
		sum-=mp[text[i]];
		i++;
		j++;

	 }
		 
		 return ans;
}


///////leetcode
class Solution {
public:
bool check(string a,string b){
    int n=a.size();
    int m=b.size();
    for(int i=0;i<=n-m;i++){
        for(int j=)
    }
}
    int repeatedStringMatch(string a, string b) {
        int n=a.size();
        int m=b.size();
        string tp=a;
        int ans=1;
        while(a.size()<b.size()){
            a=a+tp;
            ans++;
        }
        if(ck(a,b)){
            return ans;
        }
        if(ck(a+tp,b)){
            return ans;
        }
        return -1;
    }
};
