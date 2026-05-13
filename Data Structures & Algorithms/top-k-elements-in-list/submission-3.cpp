class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // map each element to a frequency count
        std::unordered_map<int, int> map; 
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // create buckets for freqency counts
        // frequency is bounded by nums.size()
        vector<vector<int>> freq(nums.size() + 1);
        for (const auto& [element, frequency] : map) {
            freq[frequency].push_back(element);
        }

        // loop through top k
        vector<int> res(k);
        int idx = 0;
        for (int j = freq.size() - 1; j >= 0 && idx < k; j--) {
            for (int l = 0; l < freq[j].size() && idx < k; l++) {
                res[idx++] = freq[j][l];
            }
        }


        return res;
    }
};
