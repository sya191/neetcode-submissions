class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        // build prefix array
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                prefix[i] = 1;
            } else {
                prefix[i] = prefix[i - 1] * nums[i - 1];
            }
        }
        // build suffix array
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i == nums.size() - 1) {
                suffix[i] = 1;
            } else {
                suffix[i] = suffix[i + 1] * nums[i + 1];
            }
        }

        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            res[i] = prefix[i] * suffix[i];
        }

        return res;
    }
};
