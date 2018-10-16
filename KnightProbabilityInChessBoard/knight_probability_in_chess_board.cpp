class Solution {
public:
	double f[102][26][26];
    double knightProbability(int N, int K, int r, int c) {
        f[0][r][c] = 1;

        for (int step = 1; step <= K; ++step)
        	for (int i = 0; i < N; ++i)
        		for (int j = 0; j < N; ++j)
        		{
        			for (int x = 1; x <= 2; ++x)
        				for (int sign1 = -1; sign1 <= 1; sign1 += 2)
        				{
        					int newx = i + sign1 * x;
        					if (newx < 0 || newx >= N)
        						continue;

        					for (int sign2 = -1; sign2 <= 1; sign2 += 2)
        					{
        						int newy = j + sign2 * (3-x);
        						if (newy < 0 || newy >= N)
        							continue;

        						f[step][i][j] += f[step-1][newx][newy];
        					}
        				}

        			f[step][i][j] /= 8.0;
        		}
        					
        	
        
        double ans = 0;
        for (int i = 0; i < N; ++i)
        	for (int j = 0; j < N; ++j)
        		ans += f[K][i][j];

        return ans;
    }
};