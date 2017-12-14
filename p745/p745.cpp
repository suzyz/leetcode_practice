class WordFilter {
public:
	int n = 0;
	vector<string> dict;
	vector<int> len;
    WordFilter(vector<string> words) {
        dict = words;
        n = dict.size();
        for (int i = 0; i < n; ++i)
        	len.push_back(dict[i].length());
    }
    
    int f(string prefix, string suffix) {
        for (int i = dict.size()-1; i >= 0; --i)
        	if (len[i] >= prefix.length() && len[i] >= suffix.length())
        	{
        		bool flag = true;
        		for (int j = 0; j < prefix.length(); ++j)
        			if (dict[i][j] != prefix[j])
        			{
        				flag = false;
        				break;
        			}

        		if (!flag)
        			continue;

        		for (int j = 0; j < suffix.length(); ++j)
        			if (dict[i][len[i]-1-j] != suffix[suffix.length()-1-j])
        			{
        				flag = false;
        				break;
        			}

        		if (flag)
        			return i;
        	}

        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
