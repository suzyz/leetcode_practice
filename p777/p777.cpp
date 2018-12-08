class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.length();

        vector<int> count(100);
        for (int i = 0; i < n; ++i)
        {
        	++count[start[i]];
        	--count[end[i]];
        }

        if (count['L'] != 0 || count['R'] != 0 || count['X'] != 0)
        	return false;

        int r = 0;
        for (int i = 0; i < n; ++i) {
        	if (start[i] == 'R')
        		++r;
        	if (end[i] == 'R')
        		--r;

        	if (end[i] == 'L' && r != 0)
        		return false;

        	if (r < 0)
        		return false;
        }

        int l = 0;
        for (int i = n-1; i >= 0; --i) {
        	if (start[i] == 'L')
        		++l;
        	if (end[i] == 'L')
        		--l;

        	if (end[i] == 'R' && l != 0)
        		return false;

        	if (l < 0)
        		return false;
        }

        return true;
    }
};