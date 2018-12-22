class Solution {
public:
    int n, tot;
    vector<int> weight, sum, width;
    vector<vector<int>> data;
    
    std::mt19937_64 rd;
    
    Solution(vector<vector<int>> rects) {
        data = rects;
        
        n = data.size();
        weight = vector<int>(n);
        sum = vector<int>(n);
        width = vector<int>(n);
        
        for (int i = 0; i < n; ++i) {
            width[i] = rects[i][2]-rects[i][0]+1;
            weight[i] = width[i] * (rects[i][3]-rects[i][1]+1);
            
            if (i > 0)
                sum[i] = sum[i-1] + weight[i];
            else
                sum[i] = weight[i];
        }
        
        tot = sum[n-1];
    }
    
    vector<int> pick() {
        int p = rd() % tot + 1;
        
        int i = 0;
        for ( ; i < n; ++i)
            if (sum[i] >= p)
                break;
        
        p = rd() % weight[i];
        int y = p / width[i];
        int x = p % width[i];
        
        vector<int> res(2);
        res[0] = data[i][0] + x;
        res[1] = data[i][1] + y;
        
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * vector<int> param_1 = obj.pick();
 */