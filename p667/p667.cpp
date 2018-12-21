class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        res.push_back(1);
        int i = k+1, j = 2;
        while (i >= j) {
            res.push_back(i);
            if (i > j)
                res.push_back(j);
            
            --i;
            ++j;
        }
        
        for (i = k+2; i <= n; ++i)
            res.push_back(i);
        
        return res;
    }
};