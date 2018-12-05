bool mycmp(string& a, string& b) {
    if (a.length() == b.length())
        return a < b;
    
    return a.length() > b.length();
}

class Solution {
public:
    int findLUSlength(vector<string>& s) {
        int n = s.size();
        
        sort(s.begin(), s.end(), mycmp);
        
        for (int i = 0; i < n; ++i)
        {
            bool ok = true;
            for (int j = i+1; j < n; ++j)
                if (s[i] == s[j]) {
                    ok = false;
                    break;
                }

            if (!ok)
                continue;

            for (int j = 0; j < i; ++j)
                if (isSubseq(s[i], s[j])) {
                    ok = false;
                    break;
                }

            if (ok)
                return s[i].length();
        }
        
        return -1;
    }

    bool isSubseq(string& a, string &b) {
        if (a == b)
            return true;

        int i = 0, j = 0;
        while (i < a.length() && j < b.length()) {
            if (a[i] == b[j])
                ++i;
            
            ++j;
        }

        return i == a.length();
    }
};