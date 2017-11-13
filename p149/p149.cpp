/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if (n < 3)
        	return n;

        int repeat[n];
        memset(repeat,-1,sizeof(repeat));

        for (int i = 0; i < n; ++i)
        	if (repeat[i]<0)
        	{
        		repeat[i] = 1;
	        	for (int j = i+1; j < n; ++j)
	        		if (repeat[j]<0)
		        	{
		        		if (points[j].x == points[i].x && points[j].y == points[i].y)
		        		{
		        			++repeat[i];
		        			repeat[j] = 0;
		        		}
		        	}
        	}

        int ans = 1;
        for (int i = 0; i < n-2; ++i)
        if (repeat[i] > 0)
        {
        	for (int j = i+1; j < n-1; ++j)
        	if (repeat[j] > 0)
        	{
        		if (2 + n-1-j <= ans)
        			break;

        		double x1 = (double)points[i].x - points[j].x;
        		double y1 = (double)points[i].y - points[j].y;
        		int count = repeat[i] + repeat[j];

        		for (int k = j+1; k < n; ++k)
        		if (repeat[k] > 0)
        		{
        			double x2 = (double)points[i].x - points[k].x;
        			double y2 = (double)points[i].y - points[k].y;

        			double tmp = ((double)x1)*y2 - ((double)x2)*y1;
        			if (fabs(tmp) < 1e-6)
        				++count;
        		}
        		ans = count > ans ? count:ans;
        	}
        }
        return ans;
    }
};
