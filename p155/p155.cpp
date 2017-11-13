class MinStack {
public:
    vector<pair<int,int>> st;
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if (st.empty())
            st.push_back(make_pair(x,x));
        else
            st.push_back(make_pair(x,min(st.back().second,x)));
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
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
