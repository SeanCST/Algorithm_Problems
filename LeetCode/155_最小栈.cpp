class MinStack
{
  public:
    stack<int> dataStack, minStack;

    MinStack()
    {

    }

    void push(int x)
    {
        if (minStack.empty() || minStack.top() >= x) {
            minStack.push(x);
        }
        dataStack.push(x);
    }

    void pop()
    {
        if (!dataStack.empty()) {
            if (dataStack.top() == minStack.top()) {
                minStack.pop();
            }
            dataStack.pop();
        }
        
    }

    int top()
    {
        return dataStack.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */