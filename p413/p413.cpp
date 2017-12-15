class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3)
        	return 0;

        int total = 0, last = 0;
        for (int i = 2; i < n; ++i)
        {
        	if (A[i] - A[i-1] == A[i-1] - A[i-2])
        		total += ++last;
        	else
        		last = 0;
        }

        return total;
    }
};
