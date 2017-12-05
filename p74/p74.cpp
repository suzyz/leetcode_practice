class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0)
        	return false;
        int m = matrix[0].size();
        if (m == 0)
        	return false;

        int st = 0, en = n-1;
        while (st < en)
        {
        	int mid = st + ((en-st)>>1);
        	if (matrix[mid][0] == target)
        		return true;
        	else
        	if (matrix[mid][0] > target)
        		en = mid;
        	else
        	{   // matrix[mid][0] < target
        		if (matrix[mid][m-1] == target)
        			return true;
        		else
	        	if (matrix[mid][m-1] > target)
	        		st = en = mid;
	        	else
	        		st = mid + 1;
        	}
        }

        if (matrix[st][0] > target || matrix[st][m-1] < target)
        	return false;

        int l = 0, r = m-1;
        while (l <= r)
        {
        	int mid = l + ((r-l)>>1);
        	if (matrix[st][mid] == target)
        		return true;
        	else
        	if (matrix[st][mid] < target)
        		l = mid+1;
        	else
        		r = mid-1;
        }

        return false;
    }
};
