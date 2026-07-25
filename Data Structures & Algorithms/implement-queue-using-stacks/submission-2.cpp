class MyQueue {
private:
    stack<int> st1;
    stack<int> st2;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while(st1.size() > 1) {
            int element = st1.top();
            st1.pop();
            st2.push(element);
        }

        int element = st1.top();
        st1.pop();
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        return element;
    }
    
    int peek() {
        while(st1.size() > 1) {
            int element = st1.top();
            st1.pop();
            st2.push(element);
        }

        int element = st1.top();
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        
        return element;
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */