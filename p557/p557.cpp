class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0,st,en;
        while (i < n)
        {
        	st = i;
        	while (i < n && s[i] != ' ')
        		++i;
        	en = i-1;
        	++i;

        	reverse_word(s,st,en);
        }
        return s;
    }

    void reverse_word(string &s,int st,int en)
    {
    	while (st < en)
    	{
    		char tmp = s[st];
    		s[st] = s[en];
    		s[en] = tmp;

    		++st;
    		--en;
    	}
    }
};
