//{ Driver Code Starts
/*TC=O(2^nlogn +2^n)
   SC=O(2^N)
   */
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
   void fun(int ind,int sum,vector<int>&arr,int N,vector<int>&sumset){
       if(ind==N){
           sumset.push_back(sum);
           return ;
       }
       fun(ind+1,sum+arr[ind],arr,N,sumset);//taken 
       fun(ind+1,sum,arr,N,sumset);//not taken
 
   }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Use recursion 
        vector<int>v;
        fun(0,0,arr,N,v);
        sort(v.begin(),v.end());
         return v;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
