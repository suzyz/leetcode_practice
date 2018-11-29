// O(N). Very efficient.
// Sliding window.
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        if (n < 2)
        	return n;

        vector<int> count(26);

        int st = 0, maxCount = 0, maxLen = 0;
        for (int en = 0; en < n; ++en) {
        	++count[s[en]-'A'];

        	maxCount = max(maxCount, count[s[en]-'A']);

        	if (en - st + 1 - maxCount > k) {
        		// Now we have:
        		// en-st+1 - curMaxCount >= en-st+1 - maxCount > k
        		// So we have to slide the window.

        		--count[s[st]-'A'];
        		++st;
        	} else
        		maxLen = max(maxLen, en - st + 1);
        }

        return maxLen;
    }
};