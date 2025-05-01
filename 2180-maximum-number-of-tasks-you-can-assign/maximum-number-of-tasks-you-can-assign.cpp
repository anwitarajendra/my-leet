class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0, right = min(tasks.size(), workers.size());

        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> available(workers.end() - k, workers.end());
        int p = pills;

        for (int i = k - 1; i >= 0; --i) {
            auto it = prev(available.end());
            if (*it >= tasks[i]) {
                available.erase(it);
            } else {
                auto low = available.lower_bound(tasks[i] - strength);
                if (low == available.end()) return false;
                available.erase(low);
                if (--p < 0) return false;
            }
        }

        return true;
    }
};