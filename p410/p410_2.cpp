// Binary Search. O(N * log(Total)).
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size(), maxv = 0;
        long long total = 0;

        for (int i = 0; i < n; ++i)
        {
            maxv = max(maxv,nums[i]);
        	total += nums[i];
        }
        
        long long l = max((long long)maxv,total/m), r = total;
        while (l < r)
        {
            long long mid = l + ((r-l) >> 1);
            if (check(nums,m,mid))
                r = mid;
            else
                l = mid+1;
        }

        return l;
    }

    bool check(vector<int>& nums, int m,long long lim)
    {
        int count = 1;
        long long sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (sum + nums[i] > lim)
            {
                ++count;
                if (count > m)
                    return false;

                sum = nums[i];
            }
            else
                sum += nums[i];
        }

        return (count <= m);
    }
};
