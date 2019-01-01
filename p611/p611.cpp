// O(N^2 * logN)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        for (int i = 0; i < n-2; ++i) {
            int a = nums[i];
            for (int j = i+1; j < n-1; ++j) {
                int b = nums[j];
                if (b-a >= nums[n-1])
                    break;
                
                if (nums[j+1] >= a+b)
                    continue;
                
                int lo = j+1, hi = n-1;
                while (lo < hi) {
                    int mid = lo + ((hi-lo)>>1);
                    if (nums[mid] > b-a)
                        hi = mid;
                    else
                        lo = mid+1;
                }
                
                int st = lo;
                
                hi = n-1;
                while (lo < hi) {
                    int mid = lo + ((hi-lo)>>1) + 1;
                    if (nums[mid] < a+b)
                        lo = mid;
                    else
                        hi = mid-1;
                }
                
                ans += hi - st + 1;
            }
        }
        
        return ans;
    }
};