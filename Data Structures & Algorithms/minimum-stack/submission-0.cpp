class MinStack {
private: 
    // for each vector pushed, track the previous min in another stack
    vector<int> data;
    vector<int> mins;
public:
    MinStack() {
    }
    
    void push(int val) {
        data.push_back(val);
        if (mins.empty()) {
            mins.push_back(val);
        } else if (val < mins[mins.size() - 1]) {
            mins.push_back(val);
        } else {
            mins.push_back(mins[mins.size() - 1]);
        }
    }
    
    void pop() {
        data.pop_back();
        mins.pop_back();
    }
    
    int top() {
        return data[data.size() - 1];
    }
    
    int getMin() {
        return mins[mins.size() - 1];
    }
};
