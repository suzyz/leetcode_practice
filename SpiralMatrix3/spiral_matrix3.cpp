class Solution {
public:
	int sideLength = 1, len = 0, count = 0, curDir = 0;
	const int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};	

    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        int tot = R*C;

        int x = r0, y = c0;
        while (res.size() < tot) {
        	if (x >= 0 && x < R && y >= 0 && y < C) {
				vector<int> tmp(2);
				tmp[0] = x;
				tmp[1] = y;
				res.push_back(tmp);
			}
			
			x += dir[curDir][0];
			y += dir[curDir][1];
			++len;

			if (len == sideLength) {
				len = 0;
				curDir = (curDir + 1)%4;

				++count;
				if (count == 2) {
					count = 0;
					++sideLength;
				} 
			}
        }

        return res;
    }
};