class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0)
        return "0";
    int negBase=-2;
    string converted = "";
    while (n != 0)
    {
        // Get remainder by negative base, it can be
        // negative also
        int remainder = n % negBase;
        n /= negBase;
 
        // if remainder is negative, add abs(base) to
        // it and add 1 to n
        if (remainder < 0)
        {
            remainder += (-negBase);
            n += 1;
        }
 
        // convert remainder to string add into the result
        converted = to_string(remainder) + converted;
    }
 
    return converted;
    }
};