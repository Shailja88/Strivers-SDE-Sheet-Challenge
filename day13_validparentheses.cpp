//using map+stack SC=O(2n)  and TC=O(n)

#include<bits/stdc++.h>
unordered_map<char,int>mp={{'(',1},{'{',2},{'[',3},{')',-1},{'}',-2},{']',-3}};
bool isValidParenthesis(string s)
{
    // Write your code here.
     stack<int>st;
    for(int i=0;i<s.size();i++){
     if(mp[s[i]]>0){
         st.push(mp[s[i]]);
     }
     else{
        if(st.empty())return false;
        if(mp[s[i]]!=-1*(st.top()))return false;
        st.pop();
    }
}
if(!st.empty())return false;
return true;
}
