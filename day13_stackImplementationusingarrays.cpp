// Stack class
#include<bits/stdc++.h>

class Stack {
    private:
   int t;
    int c;
    int *arr;  
public:
   
    Stack(int capacity) {
        // Write your code here.
        arr=new int[capacity];
        t=-1;
        c=capacity;
       
    }

    void push(int num) {
        // Write your code here.
        if(t>=c-1)
        return;
        arr[++t]=num;
        
    }

    int pop() {
        // Write your code here.
        int x=-1;
        if(t!=-1)
      { 
           x=arr[t];
          t--;
       }
       return x;
    }
    
    int top() {
        // Write your code here.
        
        if(t!=-1)
        return arr[t];
        return -1;
    }
    
    int isEmpty() {
        // Write your code here.
        if(t==-1)
        return 1;
        else return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(t==c-1)return 1;
        else return 0;
    }
    
};
