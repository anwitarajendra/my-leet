class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
      const int mod = 1e9 + 7;
        vector<long long> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        for (int step = 0; step < t; ++step) {
            vector<long long> next(26, 0);
            for (int i = 0; i < 25; ++i) {
                next[i + 1] = (next[i + 1] + freq[i]) % mod;
            }
            next[0] = (next[0] + freq[25]) % mod;
            next[1] = (next[1] + freq[25]) % mod;
            freq = next;
        }

        long long result = 0;
        for (int i = 0; i < 26; ++i) {
            result = (result + freq[i]) % mod;
        }
        return result; 
    }
};