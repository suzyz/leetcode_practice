#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
        	return 0;

        while (n > 1 && nums[n-1] == nums[n-2])
            --n;

        int l = 0, r = n-1;

        while (l < r-1 && nums[l] == nums[l+1])
            ++l;

        while (l < r)
        {
        	int mid = l + ((r-l) >> 1);
            printf("l:%d r:%d mid:%d %d %d %d\n",l,r,mid,nums[l],nums[r],nums[mid] );

        	if (nums[mid] <= nums[r])
        		r = mid;
        	else
        		l = mid + 1;
        }
        return nums[l];
    }
};


int main()
{
    Solution s;
    //int d[] = {2,4 ,5 ,6 ,7 ,0, 1, 2};
    //int d[] = {0, 1, 2,2,4 ,5 ,6 ,7 };
    int d[] = {3,3,1,3};
    vector<int> v(d,d+4);
    cout << s.findMin(v) << endl;
    return 0;
}

