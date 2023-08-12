//TC=O(n^2)
#include<bits/stdc++.h>
int func(int ini,int fi,vector<int>&a){
 int cnt=0;
    for(int i=fi-1;i>=ini;i--){
        if(a[i]<a[fi])
        cnt++;
        else 
        break;
    }
    return cnt;
}
vector<int> findStockSpans(vector<int>& a) {
    // Write your code here.
    int n=a.size();
    vector<int>ans;
    ans.push_back(1);
    for(int i=1;i<n;i++){
        ans.push_back(1+func(0,i,a));
    }
    return ans;
}
//Using stack 
#include<bits/stdc++.h>
vector<int> findStockSpans(vector<int>& prices) {
    // Using stack
    vector<int>ans;
    stack<pair<int,int>>s;
    for(auto in:prices){
          int days=1;
        while(!s.empty() && in>s.top().first)
         {
              days+=s.top().second;
              s.pop();
         }

        s.push({in,days});
        ans.push_back(days);
         }
           return ans;
}

class StockSpanner {
public:
stack<pair<int,int>>s;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int days=1;
        while(!s.empty() && price>=s.top().first){
               days+=s.top().second;
               s.pop();
                 }  
            s.push({price,days});
            return days;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
