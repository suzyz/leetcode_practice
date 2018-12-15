// O(sqrt(N)).

class Solution {
public:
    int minSteps(int n) {
        
        int res = 0, i = 2;
        while (i*i <= n) {
            while (n%i == 0) {
                res += i;
                n /= i;
            }
            ++i;
        }

        if (n > 1)
            res += n;

        return res;
    }
};