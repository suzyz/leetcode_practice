class Solution {
public:
    char findTheDifference(string s, string t) {
        int count[26] = { 0 };
        for (int i = 0; i < s.length(); ++i)
        	++count[s[i]-'a'];

        for (int i = 0; i < t.length(); ++i)
        {
        	--count[t[i]-'a'];
        	if (count[t[i]-'a'] < 0)
        		return t[i];
        }
        return 'a';
    }
};
