class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> subnum;
        subnum[0] = 1;
        int total = 0, count = 0;
        for (int n : nums) {
            total += n;
        if (subnum.find(total - k) != subnum.end()) {
                count += subnum[total - k];
            }
        subnum[total]++;
        }
        return count;
    }
};