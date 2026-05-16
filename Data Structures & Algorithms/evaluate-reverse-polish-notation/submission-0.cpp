class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<string> ts;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                int right = stoi(ts.top());
                ts.pop();
                int left = stoi(ts.top());
                ts.pop();
                ts.push(to_string(left + right));
            } else if (tokens[i] == "-") {
                     int right = stoi(ts.top());
                ts.pop();
                int left = stoi(ts.top());
                ts.pop();
                ts.push(to_string(left - right));
            } else if (tokens[i] == "*") {
                int right = stoi(ts.top());
                ts.pop();
                int left = stoi(ts.top());
                ts.pop();
                ts.push(to_string(left * right));
            } else if (tokens[i] == "/") {
                int right = stoi(ts.top());
                ts.pop();
                int left = stoi(ts.top());
                ts.pop();
                ts.push(to_string(left / right));
            } else {
                ts.push(tokens[i]);
            }
        }

        return stoi(ts.top());
    }
};
