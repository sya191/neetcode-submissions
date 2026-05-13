class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        // store each character in an unordered map with value
        // being the number of occurances 
        std::array<int, 26> char_map = {0};
        for (int i = 0; i < s.length(); i++) {
            char_map[s[i] - 'a']++;
        }

        // for the next string, decrement each value by one
        for (int i = 0; i < t.length(); i++) {
            if (char_map[t[i] - 'a'] == 0) {
                return false;
            }
            char_map[t[i] - 'a']--;
        }

        // iterate through map. If all values have 0, then they are anagrams.
        for (int i = 0; i < char_map.size(); i++) {
            if (char_map[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
