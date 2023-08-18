//TLE TC=O(N^2) 
#include<bits/stdc++.h>

bool check(string str,int ini,int fin){
 while(ini<fin){
	 if(str[ini]!=str[fin])
	 return false;
	 ini++;
	 fin--;
 }
	return true;
}
int minCharsforPalindrome(string str) {
	// Write your code here.
	int n=str.size();
	int  i=n-1;
	int cnt=0;
	while(!check(str,0,i)){
		cnt++;
		i--;
	}
	return cnt;
}

//using lps array
#include<bits/stdc++.h>
int lps(string newstr,int n){
	int nn=newstr.size();
    vector<int>lp(nn);
    lp.push_back(0);//lps of 0 is 0;
	int i=1; int len=0;
	while(i<nn){
		if(newstr[i]==newstr[len]){
			len++;
			lp[i]=len;
			i++;
		}
		else if(newstr[i]!=newstr[len]){
			if(len==0){
				lp[i]=0;
				i++;
			}
			else{
				len=lp[len-1];
			}
		}
}

	
	return (n-lp[nn-1]);
}
int minCharsforPalindrome(string str) {
	//using lps array
	int n=str.size();
	
	string newstr=str+"#";
	reverse(str.begin(),str.end());
	newstr+=str;
	
	 return (lps(newstr,n));
}

