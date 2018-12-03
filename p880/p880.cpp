// Recursive.
class Solution {
public:
    string decodeAtIndex(string s, int K) {
        int n = s.length();
        long long curLen = 0;

        for (int i = 0; i < n; ++i)
        {
        	if (s[i] >= 'a' && s[i] <= 'z') {
        		++curLen;
        		if (curLen == K)
        			return string(1, s[i]);
        	} else {
        		int d = s[i] - '0';

        		if (curLen * d >= K)
        			return decodeAtIndex(s.substr(0, i), (K-1)%curLen + 1);
        	}
        }

        return "";
    }
};