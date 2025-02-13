class Solution {
public:
    int strStr(string haystack, string needle) {
        int one=haystack.length();
        int two=needle.length();

        if(two==0)
        return 0;

        for(int i=0; i<one; i++){
            if(haystack.substr(i, two)==needle)
            return i;
        }
        return -1;
    }
};