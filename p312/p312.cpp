#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
        	return 0;
        if (n == 1)
        	return nums[0];

        nums.insert(nums.begin(),1);
        nums.push_back(1);

        vector<vector<int> > f(n+2,vector<int>(n+2,0));

        for (int i = 1; i <= n; ++i)
        	f[i][i] = nums[i-1]*nums[i]*nums[i+1];
        
        for (int i = 2; i <= n; ++i)
        {
        	for (int j = 1; j <= n-i+1; ++j)
        	{
        		int en = j+i-1;
        		f[j][en] = max(f[j+1][en] + nums[j]*nums[j-1]*nums[en+1],
        						f[j][en-1] + nums[en]*nums[j-1]*nums[en+1]);
        		for (int k = j+1; k < en; ++k)
        			f[j][en] = max(f[j][en],
        				f[j][k-1] + f[k+1][en] + nums[j-1]*nums[k]*nums[en+1]);

        		// printf("%d %d %d\n", j,en,f[j][en]);
        	}
        }

        return f[1][n];
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int d[] = {1,2,3};
	vector<int> v(d,d + sizeof(d)/sizeof(int));
	cout << s.maxCoins(v) << endl;
	return 0;
}
