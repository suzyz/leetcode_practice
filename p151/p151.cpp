class Solution {
public:
    void reverseWords(string &s) {

    	for (string::iterator it = s.begin(); it != s.end(); )
    		if (it+1 != s.end() && *it == ' ' && *(it+1) == ' ')
    			it = s.erase(it);
    		else
    			++it;

    	for (string::iterator it = s.begin(); it != s.end(); )
    		if (*it == ' ')
    			it = s.erase(it);
    		else
    			break;

        reverse(s.begin(), s.end());

        for (string::iterator it = s.begin(); it != s.end(); )
    		if (*it == ' ')
    			it = s.erase(it);
    		else
    			break;

    	int n = s.length();
    	if (n < 2)
    		return;

        int st = 0, en = 0;
        while (st < n)
        {
        	if (s[st] == ' ')
        	{
        		++st;
        		continue;
        	}

        	en = st;
        	while (en < n && s[en] != ' ')
        		++en;

        	if (en > st+1)
        		reverse(s.begin()+st,s.begin()+en);
        	st = en;
        }
    }
};
