class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // take advantage of non-decreasing order
        int start = 0;
        int end = numbers.size() - 1;

        while (start < end) {
            if (numbers[start] + numbers[end] == target) {
                break;
            } else if (numbers[start] + numbers[end] > target) {
                // end cannot be part of the solution
                end--;
            } else { // its smaller
                start++;
            }
        }

        return {start + 1, end + 1};
    }
};
