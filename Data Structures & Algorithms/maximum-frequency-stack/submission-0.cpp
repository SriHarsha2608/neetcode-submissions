class FreqStack {
private:
    unordered_map<int, int> count;
    unordered_map<int, stack<int>> stacks;
    int maxCount;

public:
    FreqStack() {
        maxCount = 0;    
    }
    
    void push(int val) {
        count[val]++;
        int cnt = count[val];
        if(cnt > maxCount) {
            maxCount = cnt;
            stacks[cnt] = stack<int>();
        }
        stacks[cnt].push(val);
    }
    
    int pop() {
        int ans = stacks[maxCount].top();
        stacks[maxCount].pop();
        count[ans]--;
        if(stacks[maxCount].empty()) {
            maxCount--;
        }

        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */