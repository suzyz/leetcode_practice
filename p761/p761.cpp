// Recursion. Very intersting.

class Solution {
public:
    string makeLargestSpecial(string S) {
        int n = S.length();
        if (n == 0)
        	return S;
        
        int count = 0, st = 0;
        vector<string> strs;

        for (int en = 0; en < n; ++en)
        {
        	if (S[en] == '1')
        		++count;
        	else
        		--count;

        	if (count == 0) {
        		strs.push_back("1" + makeLargestSpecial(
        			 S.substr(st+1, en-st-1) ) + "0");

        		st = en+1;
        	}
        }

        sort(strs.begin(), strs.end(), greater<string>());

        string res;
        for (int i = 0; i < strs.size(); ++i)
        	res += strs[i];

        return res;
    }
};