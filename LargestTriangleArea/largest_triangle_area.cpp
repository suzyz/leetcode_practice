class Solution {
public:
	double dist[52][52];

    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        int n = points.size();

        for (int i = 0; i < n-1; ++i)
        	for (int j = i+1; j < n; ++j)
        	{
        		double tmp1 = points[i][0] - points[j][0];
        		double tmp2 = points[i][1] - points[j][1];
        		tmp1 *= tmp1;
        		tmp2 *= tmp2;
        		dist[i][j] = sqrt(tmp1 + tmp2);
        	}

        for (int i = 0; i < n-2; ++i)
        	for (int j = i+1; j < n-1; ++j)
        	{
        		for (int k = j+1; k < n; ++k)
        		{
        			double p = (dist[i][j] + dist[j][k] + dist[i][k])/2;
        			double s = sqrt(p * (p-dist[i][j]) * (p-dist[j][k]) * (p-dist[i][k]));

        			if (s > ans)
        				ans = s;
        		}
        	}
        
        return ans;
    }
};