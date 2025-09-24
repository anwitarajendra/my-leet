class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;

        if ((numerator < 0) ^ (denominator < 0)) 
            result += "-";

        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        result += to_string(num / den);
        long long rem = num % den;

        if (rem == 0) return result; 

        result += ".";

        unordered_map<long long, int> seen;

        while (rem != 0) {
            if (seen.count(rem)) {
                result.insert(seen[rem], "(");
                result += ")";
                break;
            }

            seen[rem] = result.size();
            rem *= 10;
            result += to_string(rem / den);
            rem %= den;
        }

        return result;
    }
};
