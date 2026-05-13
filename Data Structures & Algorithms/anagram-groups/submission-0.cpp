class Solution {
private:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::array<int, 26> map = {0};
        // loop through first string
        for (int i = 0; i < s.length(); i++) {
            map[s[i] - 'a']++;
        }

        // loop through second string
        for (int i = 0; i < t.length(); i++) {
            if (map[t[i] - 'a'] == 0) {
                return false;
            }
            map[t[i] - 'a']--;
        }

        for (int i = 0; i < map.size(); i++) {
            if (map[i] != 0) {
                return false;
            }
        }

        return true;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // O(n^2) where n is strs.size()
        vector<vector<string>> res;
        // keep a list of all anagrams encountered
        for (int i = 0; i < strs.size(); i++) {
            // loop through res list, checking if it is an anagram of one of the sublists
            bool found = false;
            for (int j = 0; j < res.size(); j++) {
                if (isAnagram(res[j][0], strs[i])) {
                    res[j].push_back(strs[i]);
                    found = true;
                    break;
                }
            }
            // otherwise, push it as a new anagram
            if (!found) {
                res.push_back({strs[i]});
            }
        }

        return res;
    }
};
