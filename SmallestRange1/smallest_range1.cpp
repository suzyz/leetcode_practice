class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
    	if (A.size() < 2)
        	return 0;

        sort(A.begin(), A.end());

        int diff = A[A.size()-1] - A[0];

        diff -= 2*K;
        if (diff < 0)
            diff = 0;

        return diff;
    }
};