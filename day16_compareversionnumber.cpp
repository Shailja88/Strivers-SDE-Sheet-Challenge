#include <bits/stdc++.h> 
int compareVersions(string v1, string v2) 
{
    // Write your code here
    long long i=0,j=0,v1len=v1.size(),v2len=v2.size(),n1,n2;
    while(i<v1len || j<v2len){
        n1=0;
        n2=0;
        while(i<v1len && v1[i]!='.'){
            n1=n1*10+(v1[i]-'0');
            i++;
        }
        while(j<v2len && v2[j]!='.'){
            n2=n2*10 +(v2[j]-'0');
            j++;
        }
        if(n1<n2)return -1;
        else if(n1>n2)return 1;
        i++;
        j++;
    }
    return 0;
    
}
