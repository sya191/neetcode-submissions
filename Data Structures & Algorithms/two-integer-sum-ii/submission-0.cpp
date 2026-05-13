class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // take advantage of non-decreasing order
        for (int i = 0; i < numbers.size(); i++) {
            for (int j = i + 1; j < numbers.size(); j++) {
                if (numbers[i] + numbers[j] > target) {
                    break;
                } else if (numbers[i] + numbers[j] == target) {
                    return {i + 1, j + 1};
                }
            }
        }
    }
};
