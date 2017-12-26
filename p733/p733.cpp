class Solution {
public:
	int n,m;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> res = image;

		if (newColor == image[sr][sc])
        	return res;

        n = image.size();
        m = image[0].size();

        dfs(sr,sc,res,newColor,image[sr][sc]);
        return res;
    }

    void dfs(int x,int y,vector<vector<int>> &res,int newColor,int oldColor)
    {
    	if (x < 0 || y < 0 || x >=n || y >= m || res[x][y] != oldColor)
    		return;

    	res[x][y] = newColor;
    	dfs(x,y+1,res,newColor,oldColor);
    	dfs(x,y-1,res,newColor,oldColor);
    	dfs(x+1,y,res,newColor,oldColor);
    	dfs(x-1,y,res,newColor,oldColor);
    }
};
