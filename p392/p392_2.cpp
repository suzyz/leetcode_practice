// Still O(Length(T)), but seems a lot faster.
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();

        if (n > m)
        	return false;
        else
        if (n == m)
            return s == t;

        int start = 0;
        for (int i = 0; i < n; ++i)
        	if (t.find(s[i],start) != std::string::npos)
        		start = t.find(s[i],start)+1;
            else
                return false;

        return true;
    }
};
