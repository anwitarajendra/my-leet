class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
       auto check = [&](int x) {
            int n = tops.size(), rotateA = 0, rotateB = 0;
            for (int i = 0; i < n; ++i) {
                if (tops[i] != x && bottoms[i] != x)
                    return -1;
                else if (tops[i] != x)
                    rotateA++;
                else if (bottoms[i] != x)
                    rotateB++;
            }
            return min(rotateA, rotateB);
        };

        int res = check(tops[0]);
        if (res != -1)
            return res;
        return check(bottoms[0]);
    }
};