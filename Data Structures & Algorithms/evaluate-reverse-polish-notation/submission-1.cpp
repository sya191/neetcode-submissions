class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<string> ts;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                ts.push(tokens[i]);
                continue;
            }
            int right = stoi(ts.top());
            ts.pop();
            int left = stoi(ts.top());
            ts.pop();
            if (tokens[i] == "+") {
                ts.push(to_string(left + right));
            } else if (tokens[i] == "-") {
                ts.push(to_string(left - right));
            } else if (tokens[i] == "*") {
                ts.push(to_string(left * right));
            } else if (tokens[i] == "/") {
                ts.push(to_string(left / right));
            }
        }

        return stoi(ts.top());
    }
};
