// For more concise code, see version 2.
class Solution {
public:
	int maxLen[26];
    int findSubstringInWraproundString(string p) {
        int n = p.length();

        for (int i = 0; i < n; ++i)
        	p[i] -= 'a';

        int i = 0, j = 0;
        while (i < n) {
        	j = i+1;
        	while (j < n && p[j] == (p[j-1]+1)%26)
        		++j;

        	int cur = p[i];
        	maxLen[cur] = max(maxLen[cur], j-i);
        	for (int k = 1; k < 26 && k < maxLen[p[i]]; ++k)
        	{
        		int tmp = (cur+k)%26;
        		maxLen[tmp] = max(maxLen[tmp], j-i-k);
        	}

        	i = j;
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i)
        	ans += maxLen[i];

    	return ans;
    }
};