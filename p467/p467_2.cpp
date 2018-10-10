// More concise than version 1.
class Solution {
public:
	int maxLen[26];
    int findSubstringInWraproundString(string p) {
        int n = p.length();
        int count = 0;

        for (int i = 0; i < n; ++i)
        {
            if (i > 0 && (p[i]-p[i-1] == 1 || p[i]-p[i-1] == -25))
                ++count;
            else
                count = 1;

            int idx = p[i]-'a';
            maxLen[idx] = max(maxLen[idx], count);
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i)
        	ans += maxLen[i];

    	return ans;
    }
};