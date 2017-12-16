#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        int n = matrix.size();
        if (n == 0)
        	return 0;
        int m = matrix[0].size();
        if (m == 0)
        	return 0;

        vector<int> left(m+2,m), right(m+2,m), height(m+2,0);
        int res = 0;

        for (int i = 0; i < n; ++i)
        {
        	int cur_left = 0, cur_right = 0;

        	for (int j = m; j >= 1; --j)
        		if (matrix[i][j-1] == '1')
	        	{
	        		++cur_right;
	        		right[j] = min(right[j],cur_right);
	        	}
	        	else
	        	{
	        		cur_right = 0;
	        		right[j] = m;
	        	}

        	for (int j = 1; j <= m; ++j)
        		if (matrix[i][j-1] == '1')
	        	{
	        		++cur_left;
	        		left[j] = min(left[j],cur_left);

	        		++height[j];
	        		printf("%d %d l:%d r:%d h:%d\n", i,j,left[j],right[j],height[j]);
	        		res = max(res,height[j] * (right[j]+left[j]-1));
	        	}
	        	else
	        	{
	        		cur_left = height[j] = 0;
	        		left[j] = m;
	        	}
        }

        return res;
    }
};

int main()
{
	Solution s;
	vector<vector<char> > m;
	//m.push_back(vector<char>(2,'1'));
	// m.push_back(vector<char>(1,'1'));
	char r0[] = {'1','0','0','0','0','1','0','1','1','0'};
	char r1[] = {'0','1','1','1','1','1','1','0','1','0'};
	char r2[] = {'0','0','1','1','1','1','1','1','1','0'};
	m.push_back(vector<char>(r0,r0+10));
	m.push_back(vector<char>(r1,r1+10));
	m.push_back(vector<char>(r2,r2+10));
	cout << s.maximalRectangle(m) << endl;
	return 0;
}