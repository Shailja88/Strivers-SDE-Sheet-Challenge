//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(Item one,Item two){
        return (double)((double)one.value/(double)one.weight)>(double)((double)two.value/(double)two.weight);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code 
      double ans=0;
        sort(arr,arr+n,cmp);
        for(int i=0;i<n;i++){
            if(W>arr[i].weight){
                ans+=(double)arr[i].value;
                W=W-arr[i].weight;
            }
            else if(W!=0){
                ans+=(double)((W)*arr[i].value)/(double)(arr[i].weight);
                W=0;
            }
            
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends

//codestudio

#include <bits/stdc++.h> 
bool cmp(pair<int,int>&a,pair<int,int>&b){
    return ( (double)a.second/ (double)a.first) >( (double)b.second/ (double)b.first);
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
  sort(items.begin(),items.end(),cmp);
  double ans=0;

  for(int i=0;i<n;i++){
      if(w>items[i].first){
          ans+=(double)items[i].second;
          w-=items[i].first;
      }
      else if(w!=0){

      ans+=((double)(w)*(double)items[i].second)/(double)items[i].first;
      w=0;
      break;

      }
  }
  return ans;
}
