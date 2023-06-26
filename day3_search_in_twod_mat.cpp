/*  M1: brute force approach
TC=O(m*n)
SC=O(1)
*/
bool searchMatrix(vector<vector<int>>& mat, int target) {

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==target)return true;
            }
        }
        return false;
}
/*M2: better approach
As element are sorted so we can use 
binary search method 
TC=O(nlogm) n=number of rows  m=number of column 
*/
bool searchMatrix(vector<vector<int>>& mat, int target) {
    for(int i=0;i<mat.size();i++){
        int n=mat[i].size();
        int low=0;
        int high=n-1;
       int mid;
        // int mid=(low+high)/2;
        while(low<=high){
        mid=(low+high)/2;
        if(mat[i][mid]==target){
            return true;
        }
        else if(mat[i][mid]>target){
            high=mid-1;
        }
        else {
          low = mid + 1;
        }
  
        }
        
    }    
    return false;
}

//M 3: optimal approach 
bool searchMatrix(vector<vector<int>>& mat, int target) {
   int m=mat.size();
   int n=mat[0].size();
   int i=0;
   int j=n-1;
   while(i<m && j>=0){
       if(mat[i][j]==target)return true;
       else if (mat[i][j] > target) {
         j--;
       } else{
           i++;  
       }
       
   }
   return false;
}


/*M4:
optimal approach applying binary search on the entire matrix
TC= O(log(mn)) 
SC=O(1)
1  3  5  7
10 11 16 20
23 30 34 50
As elements are sorted completely 
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int l=0;
        int h=row*col-1;
        int mid;
        while(l<=h){
            mid=(l+h)/2;
            if(matrix[mid/col][mid%col]==target)return true;
            else if(matrix[mid/col][mid%col]>target){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return false;
    }
};
