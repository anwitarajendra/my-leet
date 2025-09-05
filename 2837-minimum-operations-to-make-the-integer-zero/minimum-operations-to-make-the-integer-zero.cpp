class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; k++) {
            long long target = 1LL * num1 - 1LL * k * num2;
            if (target < k) continue; 
            if (__builtin_popcountll(target) <= k) return k;
        }
        return -1;
    }
};
