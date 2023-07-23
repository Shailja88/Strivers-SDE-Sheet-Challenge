/*first brute force approach
Time limit exceeded 
*/
int singleNonDuplicate(vector<int>& arr)
{
	//TC=O(n) SC=O(1)
	int r=0;
	for(int i=0;i<arr.size();i++){
		r=r^arr[i];
	}
	return  r;
}


/*BRUTE FORCE
accepted */
int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here'
	int siz=arr.size();
	if(siz==1)return arr[0];
	else if(arr[0]!=arr[1])return arr[0];
	else if(arr[siz-1]!=arr[siz-2])return arr[siz-1];
	for(int i=1;i<siz-1;i++){
		if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1])return arr[i];
	}
	return -1;
}

/*BEST APPROACH */
int singleNonDuplicate(vector<int>& arr)
{
	/* binary search 
	TC=O(logn)
	SC=o(1)*/
	// if(arr.size()==1)return arr[0];
	// if(arr[0]!=arr[1])return arr[0];
	int low=0;
	int high=arr.size()-2;
	
	while(low<=high){
	 int mid=(low+high)>>1;
		if(arr[mid]==arr[mid^1]){
			low=mid+1;
		}
		else {
			high=mid-1;
		}
	}
	return arr[low];
}
