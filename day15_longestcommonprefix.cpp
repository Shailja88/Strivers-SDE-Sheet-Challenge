class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1)return strs[0];
        bool flag=false;
        for(int i=0;i<strs[0].size();i++){
            char s=strs[0][i];
          int j=0;
          for(j=1;j<strs.size();j++)
          {
              if(strs[j][i]==s)
              continue;
              else{
                  if(i==0)return "";
                  return strs[0].substr(0,i);
                  flag=true;
              }
          }
        }
        if(flag==false)return strs[0];
        return "";
    }
};
