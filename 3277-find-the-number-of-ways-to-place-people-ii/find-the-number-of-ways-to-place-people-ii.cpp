class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [](const auto &a, const auto &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0]; 
        });
        int count = 0;
        for (int i = 0; i < n; i++) {
            int maxYSeen = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                if (points[i][1] >= points[j][1]) {
                    if (points[j][1] > maxYSeen) {
                        count++;
                        maxYSeen = points[j][1];
                    }
                }
            }
        }
        return count;
    }
};


