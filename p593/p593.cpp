class Solution {
public:
    bool isVertical(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int x1 = p2[0] - p1[0], y1 = p2[1] - p1[1];
        int x2 = p4[0] - p3[0], y2 = p4[1] - p3[1];
        
        return x1 * x2 + y1 * y2 == 0;
    }
    
    int dist2(vector<int>& p1, vector<int>& p2) {
        int x = p1[0]-p2[0], y = p1[1] - p2[1];
        return x * x + y * y;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> rec;
        rec.push_back(p1);
        rec.push_back(p2);
        rec.push_back(p3);
        rec.push_back(p4);
        
        for (int i = 0; i < 4; ++i)
            for (int j = i+1; j < 4; ++j)
                if (rec[i] == rec[j])
                    return false;
        
        for (int i = 1; i < 4; ++i) {
            vector<vector<int>> others;
            
            bool ok = true;
            for (int j = 1; j < 4; ++j)
                if (j != i) {
                    if (!isVertical(rec[0], rec[j], rec[i], rec[j])) {
                        ok = false;
                        break;   
                    } else
                        others.push_back(rec[j]);
                }
            
            if (!ok)
                continue;
            
            if (dist2(rec[0], rec[i]) == dist2(others[0], others[1]) && dist2(rec[0], others[0]) == dist2(rec[i], others[0]) && isVertical(rec[0], rec[i], others[0], others[1]))
                return true;
        }
        
        return false;
    }
};