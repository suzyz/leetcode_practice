class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0)
        	return 0;

        heights.push_back(0);
        n++;
        int res = 0;

        stack<int> pre;
        pre.push(0);
        for (int i = 0; i < n; ++i)
        {
        	while (pre.size() > 0 && heights[i] <= heights[pre.top()])
        	{
        		int h = heights[pre.top()];
        		pre.pop();

        		int st = pre.size() == 0 ? -1:pre.top();
        		res = max(res, h * (i-1-st));
        	}
        	pre.push(i);
        }

        return res;
    }
};
