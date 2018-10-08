// Good DP.
class Solution {
public:
	const int mo = 1000000007;
	long long f[102][102];

    int numMusicPlaylists(int N, int L, int K) {
    	
    	f[0][0] = 1;
    	for (int i = 1; i <= L; ++i)
    	{
    		for (int j = 1; j <= i && j <= N; ++j)
    		{
    			f[i][j] = f[i-1][j-1]*(N-j+1)%mo;

    			if (j > K) {
    				f[i][j] += f[i-1][j]*(j-K)%mo;
    				f[i][j] %= mo;
    			}
    		}
    	}

    	return f[L][N];
    }
};