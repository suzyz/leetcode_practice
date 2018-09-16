class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        int lo = 0, hi = n-1;

        std::vector<int> res(n);

        for (int i = 0; i < n; ++i)
        	if ((A[i]&1) == 0) {
        		res[lo] = A[i];

        		lo++;
        	} else {
        		res[hi] = A[i];

        		hi--;
        	}

        return res;
    }
};