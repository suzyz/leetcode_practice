// Iterative.
class Solution {
public:
    string decodeAtIndex(string s, int K) {
        int i = 0;
        long long curLen = 0;

        while (curLen < K) {
            if (isdigit(s[i]))
                curLen *= s[i] - '0';
            else
                ++curLen;
        
            ++i;
        }

        while (curLen >= K) {
            if (curLen == K)
                return string(1, s[i]);

            if (isdigit(s[i])) {
                int d = s[i] - '0';

                curLen /= d;
                K = (K-1) % curLen + 1;
            }
            else
                --curLen;

            --i;
        }

        return "";
    }
};