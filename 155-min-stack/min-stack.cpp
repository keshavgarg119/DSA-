class MinStack {
    private:
    stack<long long>st;
    long long minElement;
public:
    MinStack() {
        while(!st.empty()) st.pop();
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            minElement = val;
        }
        else {
            if(val >= minElement) {
                st.push(val);
            }
            else {
                st.push(2LL*val-minElement);  // if val<minElement then store the new modified value
                minElement = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long top = st.top();
        st.pop();
        if(top < minElement) {
            minElement = 2LL*minElement-top;  // restore the previous min value
        }
    }
    
    int top() {
        if(st.top() >= minElement) 
            return st.top();
        else 
            return minElement;
    }
    
    int getMin() {
        return minElement;
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