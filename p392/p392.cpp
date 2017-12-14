// O(Length(T))
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();

        if (n > m)
        	return false;

        int idx = 0;
        for (int i = 0; i < m && idx < n; ++i)
        	if (t[i] == s[idx])
        		++idx;
        return idx == n;
    }
};
