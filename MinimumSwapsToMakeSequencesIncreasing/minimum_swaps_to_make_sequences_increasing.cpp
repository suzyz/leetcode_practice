class Solution {
public:
	int f[1002][2];
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        
        f[0][0] = 0;
        f[0][1] = 1;

        for (int i = 1; i < n; ++i)
        {
        	f[i][0] = f[i][1] = n;

            if (A[i] > A[i-1] && B[i] > B[i-1])
            {
                f[i][0] = min(f[i][0], f[i-1][0]);
                f[i][1] = min(f[i][1], f[i-1][1] + 1);
            }

            if (A[i] > B[i-1] && B[i] > A[i-1])
            {
                f[i][0] = min(f[i][0], f[i-1][1]);
                f[i][1] = min(f[i][1], f[i-1][0] + 1);
            }
        }

        return min(f[n-1][0], f[n-1][1]);
    }
};