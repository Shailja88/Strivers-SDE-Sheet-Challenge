//time complexity =O(2*x*y)
//space complexity =O(x)+O(y)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int x=matrix.size();
        int y=matrix[0].size();
        int row[300]={0};
        int column[300]={0};
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(matrix[i][j]==0){
                    row[i]=-1;
                    column[j]=-1;
                }
            }
        }
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(row[i]==-1 || column[j]==-1){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
