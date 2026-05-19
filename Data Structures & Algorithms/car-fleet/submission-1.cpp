class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        std::vector<std::pair<int, int>> pos_speed; 
        for (int i = 0; i < n; i++) {
            pos_speed.push_back({position[i], speed[i]});
        }
        std::sort(pos_speed.begin(), pos_speed.end());
        // need to couple speed to the position indexes
        std::stack<double> time_to_arrive;
        for (int i = n - 1; i >= 0; i--) {
            double time = (target - pos_speed[i].first) / static_cast<double>(pos_speed[i].second);
            if (i == n - 1) {
                time_to_arrive.push(time);
                continue;
            }

            if (time <= time_to_arrive.top()) {
                continue;
            } else {
                time_to_arrive.push(time);
            }
        }

        return time_to_arrive.size();
    }
};
