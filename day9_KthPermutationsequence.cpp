/*LEETCODE*
Time Complexity: O(n*n!) +O(n)
Auxiliary Space: O(1)/
class Solution {
public:
    string getPermutation(int n, int k) {
       string str="";
       int ptr=0;
       for(int i=1;i<=n;i++){
           str=str+char(i+'0');
       }
     
   do {
       if(ptr++==k-1)return str;
    } while (next_permutation(str.begin(), str.end()));

    return str;
    }
    
    };



//optimal approach
string kthPermutation(int n, int k) {
    // Write your code here.
    /*TC=O(n^2)
    SC=O(n)*/
    int fact=1;
    vector<int>v;
    string s="";
    for(int i=1;i<n;i++){
        fact=fact*i;
        v.push_back(i);
        }
        k=k-1;
        v.push_back(n);//[1,2,3,4]  fact=6 k=16
        while(true){
           s=s+to_string(v[k/fact]); //s=3  
             v.erase(v.begin()+k/fact);///[1 2 4]
             if(v.size()==0)break;
             k=k%fact;           //16%6=4 
            fact=fact/v.size(); //2  
            
        }
        return s;
}
