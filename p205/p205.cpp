class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	if (s.length() != t.length())
    		return false;

        int n = s.length();
        vector<char> from(260,'#'),to(260,'#');
        for (int i = 0; i < n; ++i)
        {
        	if (from[t[i]] == '#' && to[s[i]] == '#')
        	{
        		from[t[i]] = s[i];
        		to[s[i]] = t[i];
        	}
        	else
        	if (from[t[i]] != s[i] || to[s[i]] != t[i])
        		return false;
        }
        return true;
    }
};
