class MinStack {
public:
    stack<int> mainst;
        stack<int> minst;
    MinStack() {
        
    }
    
    void push(int val) {
        mainst.push(val);
        if(minst.empty() || val <= minst.top()){
            minst.push(val);
        }
    }
    
    void pop() {
        if(mainst.top() == minst.top()){
            minst.pop();
        }
        mainst.pop();
    }
    
    int top() {
        return mainst.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
