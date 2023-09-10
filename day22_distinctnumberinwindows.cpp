//brute force approch using set
#include <bits/stdc++.h> 
int funct(vector<int>&arr,int &i,int &j){
    set<int>st;
    for(int k=i;k<=j;k++){
        st.insert(arr[k]);
        
    }
    return st.size();
}
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    int i=0;
    int j=k-1;
  vector<int>ans;
	while(j<arr.size()){
     ans.push_back(funct(arr,i,j));
        i++;j++;
    }
    return ans;
}
//using map
#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    vector<int>ans;
    unordered_map<int,int>mp;
    
    for(int i=0;i<k;i++){
        mp[arr[i]]++;
    }
    int i=0,j=k;
    ans.push_back(mp.size());
    while(j<arr.size()){

      if(mp[arr[i]]==1)
      mp.erase(arr[i]);
       else{
           mp[arr[i]]--;
       } 
        mp[arr[j]]++;
        ans.push_back(mp.size());
        j++;
        i++;
    }
    
    return ans;
}

