// Radix Sort.

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
        	return 0;

        int maxv = nums[0];
        for (int i = 1; i < n; ++i)
        	maxv = max(maxv,nums[i]);

        vector<int> buckets[10];
        int w = 1;
        while (maxv > 0)
        {
            for (int i = 0; i < 10; ++i)
                buckets[i].clear();
            
            for (int i = 0; i < n; ++i)
            {
                int idx = nums[i]/w%10;
                buckets[idx].push_back(nums[i]);
            }

            int idx = 0;
            for (int i = 0; i < 10; ++i)
                for (int j = 0; j < buckets[i].size(); ++j)
                    nums[idx++] = buckets[i][j];

            maxv /= 10;
            w *= 10;
        }

        int max_gap = 0;
        for (int i = 0; i < n-1; ++i)
            max_gap = max(max_gap,nums[i+1] - nums[i]);

	    return max_gap;
    }
};

int main()
{
	Solution s;
	int d[] = {33,923,341,1,234,12};
	vector<int> v(d,d+6);
	cout << s.maximumGap(v) << endl;
	return 0;
}
