//using two stack
/*TC=O(n)
  SC=O(n)
  */
class Queue {
    // Define the data members(if any) here. USING  TWO STACK 
    stack<int>st1;
    stack<int>st2;
    public:
    Queue() {
        // Initialize your data structure here.
        
    }

    void enQueue(int val) {
       while(!st1.empty()){
           st2.push(st1.top());
           st1.pop();
       }

        st2.push(val);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(!st1.empty())
       { int r=st1.top();
        st1.pop();
        return r;}
        return -1;
        
    }

    int peek() {
        // Implement the peek() function here.
        if(!st1.empty())
        return st1.top();
        return -1;
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return (st1.empty());
    }
};
/*TC=amortized O(1)
  SC=O(n)
  */
class Queue {
    // Define the data members(if any) here.
    stack<int>input;
    stack<int>output;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        input.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(output.empty()==true && input.empty()==true)return -1;
       else if(output.empty()==true){
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        }
          int r=output.top();
          output.pop();
          return r;  
        
    }

    int peek() {
        // Implement the peek() function here.
         if(output.empty()==true && input.empty()==true)return -1;
       else if(output.empty()==true){
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        }
          int r=output.top();
         
          return r; 
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return (input.empty()&& output.empty());
    }
};
