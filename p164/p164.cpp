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

        int minv = nums[0], maxv = nums[0];
        for (int i = 1; i < n; ++i)
        {
        	minv = min(minv,nums[i]);
        	maxv = max(maxv,nums[i]);
        }

        if (minv == maxv)
        	return 0;

        int size_of_buckets = ceil(1.0*(maxv-minv)/(n-1))-1;
        if (size_of_buckets == 0)
        	size_of_buckets = 1;

        int num_of_buckets = ceil(1.0*(maxv-minv)/size_of_buckets)+1;
        vector<pair<int,int>> buckets(num_of_buckets,make_pair(maxv+1,minv-1));
        for (int i = 0; i < n; ++i)
        {
        	int idx = (nums[i]-minv)/size_of_buckets;
        	buckets[idx].first = min(buckets[idx].first,nums[i]);
        	buckets[idx].second = max(buckets[idx].second,nums[i]);
        }

        int max_gap = size_of_buckets, last = -1;

        for (int i = 0; i < num_of_buckets; ++i)
        	if (buckets[i].first <= maxv)
	        {
	        	if (last != -1)
	        		max_gap = max(max_gap,buckets[i].first - buckets[last].second);

	        	last = i;
	        }

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
