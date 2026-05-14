class Solution {
public:
    bool isValid(string s) {
        std::stack<char> ts;    
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                ts.push(s[i]);
                continue;
            }
            if (s[i] != ')' && s[i] != '}' && s[i] != ']') {
                continue;
            }
            if (ts.empty()) {
                return false;
            }
            char opening = ts.top();
            ts.pop();
            switch (s[i]) {
                case ')':
                    if (opening != '(') {
                        return false;
                    }
                    break;
                case '}':
                    if (opening != '{') {
                        return false;
                    }
                    break;
                case ']':
                    if (opening != '[') {
                        return false;
                    }
                    break;
            }
        }

        if (!ts.empty()) {
            return false;
        }

        return true;
    }
};
