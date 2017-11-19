//Binary Search

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if (n == 0)
        	return 0;
        int m = matrix[0].size();

        int l = matrix[0][0], r = matrix[n-1][m-1];
        while (l <= r)
        {
            int mid = l + ((r-l)>>1);

            int count = 0, j = m-1;
            for (int i = 0; i < n; ++i)
            {
                while (j>=0 && matrix[i][j] > mid)
                    --j;
                count += j+1;
            }

            if (count < k)
                l = mid+1;
            else
                r = mid-1;
        }

       	return l;
    }
};
