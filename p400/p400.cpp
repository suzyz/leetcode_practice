class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10)
            return n;
        
        int i = 0;
        long long count = 0, w = 1;
        while (count < (long long)n) {
            ++i;

            count += w * 9 * i;
            w *= 10;
        }

        w /= 10;
        count -= 9 * i * w;
        n -= count + 1;
        
        // printf("n:%d\n", n);

        int cur = w + n/i;
        n %= i;
        
        // printf("n:%d cur:%d i:%d\n", n, cur, i);

        vector<int> digits;
        while (cur > 0)
        {
            digits.push_back(cur%10);
            cur /= 10;
        }

        return digits[i - 1 - n];
    }
};