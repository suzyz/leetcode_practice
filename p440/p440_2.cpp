class Solution {
public:
    int findKthNumber(int n, int k) {
        --k;
        int cur = 1;
        while (k > 0) {
            int steps = calcDist(n, cur, cur+1);
            if (steps <= k) {
                k -= steps;
                ++cur;
            } else {
                --k;
                cur *= 10;
            }
        }

        return cur;
    }

    int calcDist(int n, long long a, long long b) {
        int dist = 0;
        while (a <= n) {
            if (b <= n)
                dist += b - a;
            else
                dist += n+1 - a;

            a *= 10;
            b *= 10;
        }

        return dist;
    }
    
};