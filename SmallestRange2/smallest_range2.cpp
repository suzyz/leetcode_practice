class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
       if (A.size() < 2)
        	return 0;
        int n = A.size();
        sort(A.begin(), A.end());
        int ans = A[n-1]-A[0];
        for (int i = 0; i < n-1; ++i) {
        	int mind = min(A[0]+K, A[i+1]-K);
        	int maxd = max(A[i]+K, A[n-1]-K);
        	if (maxd - mind < ans)
        		ans = maxd-mind;
        }

        return ans;
    }
};