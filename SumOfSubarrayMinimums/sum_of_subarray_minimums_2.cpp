// Using stack.

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        const int mo = 1000000007;
        int n = A.size(), res = 0;
        vector<int> left(n, 0), right(n, 0);
        stack<int> s1, s2;

        for (int i = 0; i < n; ++i) {

            while (!s1.empty() && A[s1.top()] >= A[i]) {
                left[i] += left[s1.top()]+1;
                s1.pop();
            }

            s1.push(i);
        }

        for (int i = n-1; i >= 0; --i) {

            while (!s2.empty() && A[s2.top()] > A[i]) {
                right[i] += right[s2.top()]+1;
                s2.pop();
            }

            s2.push(i);

            long long v = left[i]+1;
            v = v * (right[i]+1) % mo;
            v = v * A[i] % mo;

            res += v;
            if (res >= mo)
                res -= mo;
        }

        return res;
    }
};