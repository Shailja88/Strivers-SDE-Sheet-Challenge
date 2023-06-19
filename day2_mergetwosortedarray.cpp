	// BRUTE FORCE APPROACH
//codestudio
#include <bits/stdc++.h>
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
  int r=0;
	for(int i=m;i<(m+n);i++) //O(n+1)
    arr1[i]=arr2[r++];
	sort(arr1.begin(),arr1.end());  //O((m+n)log(m+n))
	return arr1;
}
//leetcode
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int r=0;
        for(int i=m;i<(m+n);i++)
            nums1[i]=nums2[r++];
        sort(nums1.begin(),nums1.end());
    }
};

/*optimal approach
TC=O(n+m)
SC=O(1)
*/
//leetcode
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //optimal solution 
        int r=m+n-1;
        m=m-1;
        n=n-1;
        while(m>=0 && n>=0){
            if(nums1[m]>nums2[n])
            nums1[r--]=nums1[m--];
            else
            nums1[r--]=nums2[n--];
        }
      while(n>=0){
       nums1[r--]=nums2[n--];
      }
      while(m>=0){
     nums1[r--]=nums1[m--];
      }
         }
};

//codestudio
#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n) {
        int x=m+n-1;
        m=m-1;
        n=n-1;
        while(n>=0){
            if(m>=0 && nums1[m]>nums2[n]){
             nums1[x--]=nums1[m--];
            }
            else{
                nums1[x--]=nums2[n--];
            }}
			return nums1;}
