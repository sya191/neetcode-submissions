class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // throw everything into a set
        std::unordered_set<int> set;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            set.insert(nums[i]);
        }
        
        // iterate through nums
        // only start checking for sequneces if we are at a valid start 
        for (int i = 0; i < nums.size(); i++) {
            if (!set.contains(nums[i] - 1)) {
                int cur = nums[i];
                int length = 1;
                while (set.contains(cur + 1)) {
                    cur++;
                    length++;
                }

                if (length > res) {
                    res = length;
                }
            }
        }

        return res;
    }
};
