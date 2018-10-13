const int maxn = 502;

class Solution {
public:
	bool graph[maxn][maxn];
	int leftMax[maxn][maxn], rightMax[maxn][maxn];
	int topMax[maxn], bottomMax[maxn];

    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int m = mines.size();
        if (m >= N*N)
        	return 0;

        for (int i = 0; i < mines.size(); ++i)
        	graph[mines[i][0]][mines[i][1]] = true;

        for (int i = 0; i < N; ++i)
        {
        	leftMax[i][0] = 1 - graph[i][0];
        	for (int j = 1; j < N; ++j)
        		if (!graph[i][j])
        			leftMax[i][j] = leftMax[i][j-1] + 1;

        	rightMax[i][N-1] = 1 - graph[i][N-1];
        	for (int j = N-2; j >= 0; --j)
        		if (!graph[i][j])
        			rightMax[i][j] = rightMax[i][j+1] + 1;
        }

        int ans = 1;
        for (int j = 0; j < N; ++j)
        {
        	topMax[0] = 1 - graph[0][j];
        	for (int i = 1; i < N; ++i)
        		if (!graph[i][j])
        			topMax[i] = topMax[i-1] + 1;
        		else
        			topMax[i] = 0;

        	bottomMax[N-1] = 1 - graph[N-1][j];
        	for (int i = N-2; i >= 0; --i)
        		if (!graph[i][j])
        		{
        			bottomMax[i] = bottomMax[i+1] + 1;

        			int curLen = min4(bottomMax[i], topMax[i],
        				  leftMax[i][j], rightMax[i][j]);

        			ans = max(ans, curLen);
        		} else
        			bottomMax[i] = 0;
        }

        return ans;
    }

    int min4(int a, int b, int c, int d) {
    	if (b < a)
    		a = b;
    	if (c < a)
    		a = c;
    	if (d < a)
    		a = d;
    	return a;
    }
};