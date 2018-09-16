class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        const int mo = 1000000007;
        int n = A.size(), res = 0;
        vector<int> left(n, 0), right(n, 0);
        
        for (int i = 0; i < n; ++i) {
        	int j = i-1;
            while (j >= 0 && A[j] >= A[i]) {
                left[i] += left[j]+1;
                j -= left[j];
                j--;
            }
        }

        for (int i = n-1; i >= 0; --i) {
            int j = i+1;
            while (j < n && A[j] > A[i]) {
                right[i] += right[j]+1;
                j += right[j]+1;
            }

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