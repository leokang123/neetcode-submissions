class MyStack {
private:
    vector<int> st{};
    int p{};
public:
    MyStack(): st(1000) {
        
    }
    
    void push(int x) {
        st[p++] = x;
    }
    
    int pop() {
        return st[--p];
    }
    
    int top() {
        return st[p-1];
    }
    
    bool empty() {
        return p == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */