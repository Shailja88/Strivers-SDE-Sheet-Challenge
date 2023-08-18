/*valid anagram 
method 1:
TC=O(2nlogn)
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return (s==t);
    }
};

//multiset
class Solution {
public:
    bool isAnagram(string s, string t) {
       multiset<char>s1;
       multiset<char>s2;
        for(auto in:s){
            s1.insert(in);
        }
        for(auto in:t){
            s2.insert(in);

        }
        return (s1==s2);
    }
};
///TC=O(n+m)
//SC=O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        ///using
        vector<int>v(26,0);
         for(auto in: s){
           v[in-'a']++;
         }
          for(auto in:t){
              v[in-'a']--;
          }
          for(auto in:v){
              if(in!=0)return false;
          }
          return true;
         }
};
