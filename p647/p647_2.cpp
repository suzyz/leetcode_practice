// Brutal force. O(1) space.
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        if (n == 0)
        	return 0;

        int count = 0;
        for (int i = 0; i < n; ++i)
        {
            count += get_num(s,i,i);
            if (i < n-1)
                count += get_num(s,i,i+1);
        }
        
        return count;
    }

    int get_num(string &s, int x,int y)
    {
        int res = 0;
        while (x >= 0 && y < s.length() && s[x] == s[y])
        {
            ++res;
            --x;
            ++y;
        }

        return res;
    }
};
