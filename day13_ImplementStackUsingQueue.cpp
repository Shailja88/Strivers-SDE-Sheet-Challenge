//using two queues

#include<bits/stdc++.h>
class Stack {
	// Define the data members.
  queue<int>q1;
  queue<int>q2;

   public:
    Stack() {
        // Implement the Constructor.
     
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return (q1.empty());
    }

    void push(int element) {
        // Implement the push() function.
        q2.push(element);
        while(!q1.empty()){
          q2.push(q1.front());
          q1.pop();
        }
        while(!q2.empty()){
          q1.push(q2.front());
          q2.pop();
        }
    }

    int pop() {
      int x=-1;
        // Implement the pop() function.
        if(!q1.empty()){
           x=q1.front();
          q1.pop();
          
        }
        return x;
    }

    int top() {
        // Implement the top() function.
        if(q1.size()!=0)
        return q1.front(); 
        return -1;
    }
};






//using one queues
#include<bits/stdc++.h>
class Stack {
	// Define the data members.
 queue<int>q1;
   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
       
        return q1.size();
    }

    bool isEmpty() {
      
        return q1.empty();
    }

    void push(int element) {
        // Implement the push() function.
        q1.push(element);
        int x=q1.size();
        int i=1;
        while(i<x){
          q1.push(q1.front());
          q1.pop();
          i++;
        }
        
    }

    int pop() {
        // Implement the pop() function.
        if(q1.size()==0)return -1;
        int x=q1.front();
        q1.pop();
        return x;
    }

    int top() {
        // Implement the top() function.
        if(q1.size()==0)return -1;
        return q1.front();
    }
};
