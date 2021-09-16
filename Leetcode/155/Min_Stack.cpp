class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int, int>> sta;
    MinStack() {
        
    }
    
    void push(int val) {
        if(sta.size()==0) sta.push({val, val});
        else sta.push({val, min(sta.top().second, val)});
    }
    
    void pop() {
        sta.pop();
    }
    
    int top() {
        return sta.top().first;
    }
    
    int getMin() {
        return sta.top().second;
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
