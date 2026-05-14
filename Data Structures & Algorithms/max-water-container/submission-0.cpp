class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = 0;
        int start = 0;
        int end = heights.size() - 1;
        while (start < end) {
            int height = std::min(heights[start], heights[end]);
            int vol = height * (end - start);
            if (vol > max) {
                max = vol;
            }
            heights[start] < heights[end] ? start++ : end--;
        }

        return max;
    }
};
