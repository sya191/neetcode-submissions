class Solution {
public:
    bool isPalindrome(string s) {
        // convert to lower
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 32;
            }
        }
        // keep track of two pointers
        int start = 0;
        int end = s.length() - 1;
        while (start < end) {
            if (!std::isalnum(s[start])) {
                start++;
                continue;
            }
            if (!std::isalnum(s[end])) {
                end--;
                continue;
            }
            if (s[start++] != s[end--]) {
                return false;
            }
        }

        return true;
    }
};
