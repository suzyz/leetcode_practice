class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size(), ans = 0;
        unordered_map<int,int> sum;

        for (int i = 0; i < n; ++i)
        	for (int j = 0; j < n; ++j)
        		++sum[A[i]+B[j]];
        for (int i = 0; i < n; ++i)
        	for (int j = 0; j < n; ++j)
        		ans += sum[0-C[i]-D[j]];
        	
        return ans;
    }
};
