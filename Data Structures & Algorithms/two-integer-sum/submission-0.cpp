class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> res = {-1, -1};
        // iterate through array
        // store each encountered number in a unordered map
        // if set contains target - nums[i], then return the number
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.contains(target - nums[i])) {
                res[0] = map[target - nums[i]];
                res[1] = i;
                break;
            } else {
                // store in hash
                map[nums[i]] = i;
            }
        }

        return res;
    }
};
