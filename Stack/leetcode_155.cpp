//Min Stack

// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() --  the minimum element in the stack.
//  
// Example 1:
// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]
// Output
// [null,null,null,null,-3,null,0,-2]
//
// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2
//  
//
// Constraints:
// Methods pop, top and getMin operations will always be called on non-empty stacks.


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Easy


//利用 vector 来构造栈
class MinStack {
private:
    vector<int> v;
public:
    /** initialize your data structure here. */
    MinStack() 
    {
        
    }
    
    void push(int x)
    {
        v.push_back(x);
    }
    
    void pop() 
    {
        v.pop_back();
    }
    
    int top() 
    {
        int temp = v.back();
        return temp;
    }
    
    int getMin() 
    {
        auto smallest = min_element(begin(v),end(v));
        return *smallest;
    }
};



/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



int main()
{
    MinStack *minstack = new MinStack();
    minstack->push(-2);
    minstack->push(0);
    minstack->push(-3);
    int t = minstack->getMin();
    cout<<t<<endl;
    minstack->pop();
    t = minstack->top();
    cout<<t<<endl;
    t = minstack->getMin();
    cout<<t<<endl;
    system("pause");
    return 0;
}