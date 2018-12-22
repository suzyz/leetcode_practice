class Solution {
public:
    int d2(vector<int>& p1, vector<int>& p2) {
        int x = p1[0] - p2[0], y = p1[1] - p2[1];
        return x * x + y * y;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> s({d2(p1, p2), d2(p1, p3), d2(p1, p4),
            d2(p2, p3), d2(p2, p4), d2(p3, p4)});

        return !s.count(0) && s.size() == 2;
    }
};