class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
       auto gain = [&](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };
        priority_queue<vector<double>> pq;
        for (auto &c : classes) {
            pq.push({gain(c[0], c[1]), (double)c[0], (double)c[1]});
        }
        while (extraStudents--) {
            auto top = pq.top(); pq.pop();
            double pass = top[1], total = top[2];
            pass += 1; total += 1;
            pq.push({gain((int)pass, (int)total), pass, total});
        }
        double sum = 0;
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            sum += top[1] / top[2];
        }
        return sum / classes.size();
    }
};
