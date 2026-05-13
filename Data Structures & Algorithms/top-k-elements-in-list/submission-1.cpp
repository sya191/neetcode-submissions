class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // map each element to a frequency count
        std::unordered_map<int, int> map; 
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        // iterate through frequency count at the end to get the k most
        vector<int> res(k);
        for (int i = 0; i < k; i++) {
            int most = 0;
            int element;
            for (auto it = map.begin(); it != map.end(); it++) {
                if (it->second > most) {
                    element = it->first;
                    most = it->second;
                }
            }  
            res[i] = element;
            map[element] = 0;
        }

        return res;
        
    }
};
