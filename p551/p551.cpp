class Solution {
public:
    bool checkRecord(string s) {
        int n = s.length();
        
        int countA = 0;
        for (int i = 0; i < n; ++i)
            if (s[i] == 'A') {
                if (countA)
                    return false;
                ++countA;
            } else
                if (s[i] == 'L') {
                    if (i > 1 && s[i-1] == 'L' && s[i-2] == 'L')
                        return false;
                }
        
        return true;
    }
};