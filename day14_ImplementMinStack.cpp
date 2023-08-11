/*Using stack 
TC=O(1)
SC=O(2N)
*/
#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	stack<pair<int,int>>st;
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			int mini;
			if(st.empty())mini=num;
			else{
				mini=min(st.top().second,num);
			}
			// Write your code here.
			
			st.push({num,mini});
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(st.empty())return -1;
			int r=st.top().first;
			st.pop();
			return r;
			
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
				if(st.empty())return -1;
				return st.top().first;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
				if(st.empty())return -1;
				return st.top().second;
		}
};


//Optimal solution 
class MinStack {
public:
stack<int>s;
stack<int>min;

    MinStack() {
        
    }
    
    void push(int val) {
        if(min.empty() || min.top()>=val){
            min.push(val);
        }
        s.push(val);
    }
    
    void pop() {
   
        if(s.top()==min.top())
         min.pop();
         s.pop();
        
        } 
    
    
    int top() {
 
        return s.top();
    
    }
    
    int getMin() {
     
        return min.top();
 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
