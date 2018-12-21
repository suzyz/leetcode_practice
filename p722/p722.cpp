class Solution {
public:
    vector<string> removeComments(vector<string>& s) {
        vector<string> ans;
        
        int i = 0, n = s.size();
        while (i < n) {
            if (s[i].length() == 0) {
                ++i;
                continue;
            }
            
            int j = 0, id = 0;
            for ( ; j < s[i].length()-1; ++j)
                if (s[i][j] == '/') {
                    if (s[i][j+1] == '/') {
                        id = 1;
                        break;
                    } else if (s[i][j+1] == '*') {
                        id = 2;
                        break;
                    }
                }
            
            if (id == 0) {
                ans.push_back(s[i]);
                ++i;
                continue;
            }
            
            if (id == 1) {
                if (j > 0)
                    ans.push_back(s[i].substr(0, j));
                ++i;
                continue;
            }
            
            string res = s[i].substr(0, j);
            j += 2;
            int pos = -1;
            for ( ; j < s[i].length()-1; ++j)
                if (s[i][j] == '*' && s[i][j+1] == '/') {
                    pos = j;
                    break;
                }
            
            while (pos == -1 && i < n-1) {
                ++i;
                if (s[i].length() < 2)
                    continue;
                
                for (int k = 0; k < s[i].length()-1; ++k) {
                    if (s[i][k] == '*' && s[i][k+1] == '/') {
                        pos = k;
                        break;
                    }
                }
            }
            
            res += s[i].substr(pos+2);
            if (res.length() > 0)
                s[i] = res;
            else
                ++i;
        }
        
        return ans;
    }
};