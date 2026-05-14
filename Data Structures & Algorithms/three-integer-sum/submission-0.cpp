class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        // two pointer sol
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            // we've seen this number in this pos, so skip
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            // fix the first number
            int start = i + 1;
            int end = nums.size() - 1;
            int target = -nums[i];
            while (start < end) {
                if (nums[start] + nums[end] > target) {
                    // need something smaller
                    end--;
                } else if (nums[start] + nums[end] < target) {
                    // need something bigger
                    start++;
                } else {
                    res.push_back({nums[start], nums[end], nums[i]});
                    // there could be multiple valid triplets, so push one of the indexes to a new number
                    start++;
                    while (nums[start] == nums[start - 1]) {
                        start++;
                    }
                }
            }
        }

        return res;
    }
};
