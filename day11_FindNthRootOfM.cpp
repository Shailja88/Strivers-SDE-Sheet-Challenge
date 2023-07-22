//method 1
int NthRoot(int n, int m) {

  // TC O(sqrt(m))
  for(int i=1;i<=sqrt(m);i++){
    long long x=pow(i,n);
     if(x==m)return i;
    else  if(x>m)return -1;
  }
}

//method 2
int NthRoot(int n, int m) {
  // Write your code here.
  int s=1,e=m,mid=0;
  while(s<=e){
    mid=(s+e)/2;
    if(pow(mid,n)==m)return mid;
    else if(pow(mid,n)>m)
      e=mid-1;
    else s=mid+1;
  }
  return -1;
}
