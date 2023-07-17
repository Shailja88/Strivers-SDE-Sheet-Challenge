//greedy method
/*platform khali kro j aage bdhao 
platform bhro i aage bdhao
TC=O(2nlogn)+O(2n)
SC=O(1)
*/
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    int ans=0;
    int i=1;
    int cnt=1;
    int j=0;
    while(i<n && j<n){
        if(at[i]>dt[j]){
            cnt--;
            j++;
        }
        else if(at[i]<=dt[j]){
            cnt++;
            i++;
        }
        ans=max(ans,cnt);
    }
    if(ans==0)return 1;
    return ans;
}
