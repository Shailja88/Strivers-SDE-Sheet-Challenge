/*BRUTE FORCE 
TC=O(2n)
SC=O(n+1)
*/
//codestudio
#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	pair <int,int>p;
	int ar[n+1]={0};

	for(int i=0;i<n;i++){
		ar[arr[i]]++;
	}
	for(int i=1;i<n+1;i++){
		if(ar[i]==0){
			p.first=i;
		}
		if(ar[i]==2)p.second=i;
	}
	return p;
}
//interview bit
vector<int> Solution::repeatedNumber(const vector<int> &arr) {
    int n=arr.size();
    int first;int second;
   vector<int>v;
	int ar[n+1]={0};
	
	for(int i=0;i<n;i++){
		ar[arr[i]]++;
	}
	for(int i=1;i<n+1;i++){
		if(ar[i]==0){
			first=i;
		}
		if(ar[i]==2)second=i;
	}
        v.push_back(second);
    v.push_back(first);

	return v;
}


///optimal approach 1

#include <bits/stdc++.h>

 

pair<int,int> missingAndRepeating(vector<int> &a, int n1)

{
 long long n=n1;
    pair<int,int>pr;

long long SN=(n*(n+1))/2;

long long S2N=(n*(n+1)*(2*n+1))/6;

long long S=0,S2=0;

for(int i=0;i<n;i++){

    S+=a[i];

    S2+=(long long)a[i]*(long long)a[i];

}

    long long val1=S-SN;

    long long val2=S2-S2N;

    val2=val2/val1;

    int x=(val1+val2)/2;

    int y=x-val1;

      pr.first=y;

      pr.second=x;

      return pr;

}
//optimal approach 2
/* TC=O(n)
SC = O(1)
*/

#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n1)
{
    long long n=n1;
    int xr=0;
    for(int i=0;i<n;i++){
        xr=xr^arr[i];
        xr=xr^(i+1);
    }
	int bitNo=0;
    while(1){
        if((xr&(1<<bitNo))!=0)
        break;
        bitNo++;
    }
    int zero=0;
    int one=0;
    for(int i=0;i<n;i++){
        if((arr[i] &(1<<bitNo))!=0)
        one =one^arr[i];
        else
        zero=zero^arr[i];
    }
    for (int i = 1; i <= n; i++) {
      if ((i & (1 << bitNo)) != 0)
        one = one ^ i;
      else
        zero = zero ^ i;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    if(arr[i]==zero)cnt++;
     if(cnt==2)return {one,zero};
     return {zero,one};

}

 
