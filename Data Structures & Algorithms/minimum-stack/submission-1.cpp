class MinStack {
private:
    stack<int>st;
    stack<int>st2;
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(st2.empty()||st2.top()>=val){
            st2.push(val);
        }
    }
    
    void pop() {
        if(st.top()==st2.top())st2.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return st2.top();
    }
};
