class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<std::pair<int, int>> ts;
        // maintain stack of monotonically increasing order
        // if the current element is less than top(), pop that element and
        // calculate the limiting height area rectangle for the popped element
        // keep popping until we encounter an element that doesn't get limited
        // by the current height bar
        int max = 0;
        for (int i = 0; i < heights.size(); i++) {
            int idx = i;
            while (!ts.empty() && ts.top().first >= heights[i]) {
                std::pair<int, int>& top = ts.top();
                int area = top.first * (i - top.second);
                if (area > max) {
                    max = area;
                }
                ts.pop();
                // store the popped idx as the next idx to be pushed
                // this is because the stack maintains an increasing order
                // the limiting height to the left is already popped
                idx = top.second;
            } 

            ts.push({heights[i], idx});
        }

        // bars are left in the stack, and are strictly increasing
        // for each bar, just extend them to the right
        // cannot extend to the left, because bars are strictly increasing
        int n = ts.size();
        for (int i = 0; i < n; i++) {
            std::pair<int, int>& element = ts.top();
            int width = heights.size() - element.second;
            int res = width * element.first;
            if (res > max) {
                max = res;
            }
            ts.pop();
        }

        return max;
    }
};
