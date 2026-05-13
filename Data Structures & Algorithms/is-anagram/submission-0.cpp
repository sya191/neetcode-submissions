class Solution {
public:
    bool isAnagram(string s, string t) {
        // store each character in an unordered map with value
        // being the number of occurances 
        std::unordered_map<char, int> map;
        for (int i = 0; i < s.length(); i++) {
            map[s[i]]++;
        }

        // for the next string, decrement each value by one
        for (int i = 0; i < t.length(); i++) {
            map[t[i]]--;
        }

        // iterate through map. If all values have 0, then they are anagrams.
        for (auto it = map.begin(); it != map.end(); it++) {
            if (it->second != 0) {
                return false;
            }
        }

        return true;
    }
};
