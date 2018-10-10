class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size(), ans = 0;
        unordered_set<int> s(A.begin(), A.end());

       	for (int i = 0; i < n-2; ++i)
       	{
       		int lim = min(n-1, n+1-ans);

       		for (int j = i+1; j < lim; ++j)
       		{
       			int a = A[i], b = A[j], c = A[i] + A[j], len = 2;
       			while (s.count(c)) {
       				a = b;
       				b = c;
       				c = a + b;

       				++len;
       			}

       			if (len > 2)
       				ans = max(ans, len);
       		}
       	}

       	return ans;
    }
};