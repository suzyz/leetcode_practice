class Solution {
public:
	const int mo = 1000000007;
	bool vis[52][52][52];
	int f[52][52][52];

    int findPaths(int m, int n, int N, int i, int j) {
        
        memset(vis,0,sizeof(vis));
        memset(f,0,sizeof(f));

        return dfs(N,i+1,j+1,m,n);
    }

    int dfs(int steps,int x,int y,int m,int n)
    {
    	if (x == 0 || y == 0 || x > m || y > n)
    		return 1;

    	if (steps == 0)
    		return 0;

    	if (vis[steps][x][y])
    		return f[steps][x][y];

    	vis[steps][x][y] = true;

    	long long sum = dfs(steps-1,x+1,y,m,n) + 
    					dfs(steps-1,x-1,y,m,n) + 
    					dfs(steps-1,x,y+1,m,n) + 
    					dfs(steps-1,x,y-1,m,n);

    	f[steps][x][y] = sum%mo;
    	return f[steps][x][y];
    }
};
