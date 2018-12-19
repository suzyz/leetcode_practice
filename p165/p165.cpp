class Solution {
public:
    int compareVersion(string v1, string v2) {
        if (v1 == v2)
            return 0;
        
        int n = v1.length(), m = v2.length(), i = 0, j = 0;
        while (i < n && j < m) {
            int d1 = 0, d2 = 0;
            while (i < n && v1[i] != '.') {
                d1 = d1 * 10 + v1[i] - '0';
                ++i;
            }
            ++i;
            
            while (j < m && v2[j] != '.') {
                d2 = d2 * 10 + v2[j] - '0';
                ++j;
            }
            ++j;
            
            if (d1 < d2)
                return -1;
            if (d1 > d2)
                return 1;
        }
        
        if (i < n) {
            while (i < n) {
                int d1 = 0;
                while (i < n && v1[i] != '.') {
                    d1 = d1 * 10 + v1[i] - '0';
                    ++i;
                }
                ++i;
                
                if (d1 != 0)
                    return 1;
            }
        } else if (j < m) {
            int d2 = 0;
            while (j < m) {
                while (j < m && v2[j] != '.') {
                    d2 = d2 * 10 + v2[j] - '0';
                    ++j;
                }
                ++j;    
                
                if (d2 != 0)
                    return -1;
            }
        }
        
        return 0;
    }
};