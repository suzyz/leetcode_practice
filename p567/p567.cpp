class Solution {
public:
    bool check(vector<int>& c1, vector<int>& c2) {
        for (int j = 0; j < 26; ++j)
            if (c1[j] != c2[j])
                return false;
        
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n > m)
            return false;
        
        vector<int> c1(26), c2(26);
        for (int i = 0; i < n; ++i) {
            ++c1[s1[i]-'a'];
            ++c2[s2[i]-'a'];   
        }
        
        if (check(c1, c2))
            return true;
        
        for (int i = n; i < m; ++i) {
            ++c2[s2[i]-'a'];
            --c2[s2[i-n]-'a'];
            
            if (check(c1, c2))
                return true;
        }
        
        return false;
    }
};