class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0, l = 0, r = height.size()-1, low, cur_level = 0;
        
        while (l < r)
        {
            if (height[l] < height[r])
                low = height[l++];
            else
                low = height[r--];

            cur_level = max(cur_level,low);
            sum += cur_level - low;
        }

        return sum;
    }
};
