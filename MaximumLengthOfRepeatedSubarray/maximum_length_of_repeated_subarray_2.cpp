// O(N) space.
class Solution {
public:
	int f[1002];
    int findLength(vector<int>& A, vector<int>& B) {
    	int n = A.size(), m = B.size(), ans = 0;

        for (int i = 0; i < n; ++i)
        	for (int j = m-1; j >= 0; --j)
        		if (A[i] == B[j])
        		{
        			int pre;
        			if (i == 0 || j == 0)
        				pre = 0;
        			else
        				pre = f[j-1];

        			f[j] = pre+1;
        			ans = max(ans, f[j]);
        		} else
                    f[j] = 0;
        		
       	return ans;
    }
};