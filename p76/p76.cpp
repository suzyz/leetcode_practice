class Solution {
public:
    string minWindow(string s, string t) {
    	if (t.length() == 0)
    		return "";

        int count[300];
        memset(count,0,sizeof(count));

        int mint = 260, maxt = 0;
        for (int i = 0; i < t.length(); ++i)
        {
        	++count[t[i]];
        	if (t[i] > maxt)
        		maxt = t[i];
        	if (t[i] < mint)
        		mint = t[i];
        }

        int st = 0, best_st = 0, len = s.length()+1;
        for (int i = 0; i < s.length(); ++i)
        {
        	--count[s[i]];
        	while (st < i && count[s[st]] < 0)
        	{
        		++count[s[st]];
        		++st;
        	}

        	if (i - st + 1 >= len)
        		continue;

        	bool flag = true;
        	for (int j = mint; j <= maxt; ++j)
        		if (count[j] > 0)
        		{
        			flag = false;
        			break;
        		}

        	if (!flag)
        		continue;

        	best_st = st;
        	len = i - st + 1;
        }

        if (len > s.length())
        	return "";

        string res = s.substr(best_st,len);
        return res;
    }
};
