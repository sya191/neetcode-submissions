class Solution {
public:
    int trap(vector<int>& height) {
        // get the greatest elevation up to point[i]
        vector<int> prefix(height.size(), 0);
        for (int i = 0; i < height.size(); i++) {
            if (i == 0) {
                prefix[i] = height[i];
            } else {
                prefix[i] = std::max(height[i], prefix[i - 1]);
            }
        }
        vector<int> suffix(height.size(), 0);
        for (int i = height.size() - 1; i >= 0; i--) {
            if (i == height.size() - 1) {
                suffix[i] = height[height.size() - 1];
            } else {
                suffix[i] = std::max(height[i], suffix[i + 1]);
            }
        }

        int volume = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            // total volume for index i is
            // min(prefix[i], suffix[i]) - height[i] 
            // take the tallest walls either side of i (pref and suff)
            // take the min of these walls and take the difference with the height
            volume += std::min(prefix[i], suffix[i]) - height[i];
        }

        return volume;
    }
};
