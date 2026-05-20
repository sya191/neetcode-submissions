class Solution {
public:
    int search(vector<int>& nums, int target) {
        int right = nums.size() - 1;
        int left = 0;
        while (right - left >= 0) {
            int middle = left + (right - left) / 2;
            if (nums[middle] == target) {
                return middle;
            }
            //  target is smaller than middle -> look left
            if (nums[middle] > target) {
                // middle - 1 becomes the new right boundary
                right = middle - 1;
            } else if (nums[middle] < target) {
                left = middle + 1;
            }
        }

        return -1;
    }
};
