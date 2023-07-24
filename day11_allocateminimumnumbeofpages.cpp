
#include <bits/stdc++.h> 
bool isPossible(long long mid,vector<int>&time,int m,int  n){
	//m mtlb chapter given
	//n mtlb days given
	//time[i] mtlb ek chapter ko complete krne k liye itna time lg rha hai 
	//mid = itna max time diya gya hai 
	 int days=1;
   long long  timee=0;
   for(int i=0;i<m;i++){
	   if(timee+time[i]<=mid){
		   timee=timee+time[i];
	   }
	   else{
		   timee=time[i];
		   days++;
		   if(days>n|| time[i]>mid)return false;

	   }
   }
return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
	long long sum=0;
    long long  low=0;
	for(int  i=0;i<m;i++){
		sum+=time[i];
	}
	long long high=sum;
	
	long long ans=-1;
	while(low<=high){
            long long mid=(low+high)/2;
			if(isPossible(mid,time,m,n)){
				ans=mid;
				high=mid-1;
			}
			else {
				low=mid+1;
			}
	}
	return ans;
}
