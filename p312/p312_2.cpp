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

        ++n;
        vector<vector<int> > f(n+2,vector<int>(n+2,0));

        for (int i = 2; i <= n; ++i)
        {
        	for (int j = 0; j <= n-i; ++j)
        	{
        		int en = j+i;
        		for (int k = j+1; k < en; ++k)
        			f[j][en] = max(f[j][en],
        				f[j][k] + f[k][en] + nums[j]*nums[k]*nums[en]);
        	}
        }

        return f[0][n];
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
