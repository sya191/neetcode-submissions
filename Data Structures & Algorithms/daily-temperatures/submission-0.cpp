class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> res(temperatures.size(), 0);
        // stack of unprocessed elements
        std::stack<vector<int>> ts;
        ts.push({0, temperatures[0]});
        for (int i = 1; i < temperatures.size(); i++) {
            // we've found a warmer temp for the unprocessed element, keep popping
            while (!ts.empty() && temperatures[i] > ts.top()[1]) {
                res[ts.top()[0]] = i - ts.top()[0];
                ts.pop();
            }

            // otherwise, just push the current temp
            ts.push({i, temperatures[i]});
        }
        
        return res;
    }
};
