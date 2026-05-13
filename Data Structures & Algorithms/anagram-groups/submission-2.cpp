class Solution {

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> map;
        for (int i = 0; i < strs.size(); i++) {
            // build frequency array
            std::array<int, 26> freq = {0};
            for (int j = 0; j < strs[i].length(); j++) {
                freq[strs[i][j] - 'a']++;
            }
            // build string from array as key
            string key = "";
            for (int k = 0; k < freq.size(); k++) {
                // need seperator for each freq value
                // i.e. [1,1] != [11] 
                // "11" == "11"
                key += "#" + std::to_string(freq[k]);
            }
            map[key].push_back(strs[i]);
        }

        std::vector<vector<string>> res;
        // build the final vector  
        for (auto it = map.begin(); it != map.end(); it++) {
            res.push_back(it->second);
        }

        return res;
    }
};