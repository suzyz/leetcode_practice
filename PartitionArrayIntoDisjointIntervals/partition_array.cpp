class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int n = A.size();

        vector<int> right(n+1);

        right[n-1] = A[n-1];
        for (int i = n-2; i >= 0; --i)
        	right[i] = min(A[i], right[i+1]);

        int left = INT_MIN;
        for (int i = 0; i < n; ++i) {
        	left = max(left, A[i]);
        	if (left <= right[i+1])
        		return i+1;
        }
        
        return n;
    }
};