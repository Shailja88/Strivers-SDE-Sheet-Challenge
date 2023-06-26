/* leetcode calculate pow(x,n) 
TC = O(logn)
SC = O(1)
if n is odd ans=ans*x and n=n-1;
if n is even x=x*x and n=n/2;
*/
class Solution {
public:
    double myPow(double x, int n) {
        double ans=pow(x,n);
        return  ans;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn=n;
        if(nn<0)nn=-1*nn;
        while(nn>0){
            if(nn%2==1){
                ans=ans*x;
                nn=nn-1;
            }
            else{
                  x=x*x;
                  nn=nn/2;
            }
        }

        if(n<0)ans=(double)(1.0)/(double)(ans);
        return ans;
    }
};

///codestudio modular exponentiation
#include <bits/stdc++.h>

int modularExponentiation(int xx, int n, int m) {
long long ans=1;
long long x=xx;///important 
while(n){
	if(n&1){
		ans=(((ans)%m)*(x%m))%m;
		n=n-1;
	}
	else{
		x=((x%m)*(x%m))%m;
		n=n>>1;
	}
	
}
return (int)(ans%m);
}

