class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int n = str.length();
        unordered_map<string,char> p;
        unordered_map<char,string> w;

        int idx = 0;
        for (int i = 0; i < n ; )
        {
        	if (idx >= pattern.length())
        		return false;

        	int j = str.find(' ',i);
        	if (j == std::string::npos)
        		j = n;

        	if (j > i)
        	{
	        	string tmp = str.substr(i,j-i);
	        	if (p.count(tmp) == 0 && w.count(pattern[idx]) == 0)
	        	{
	        		p[tmp] = pattern[idx];
	        		w[pattern[idx]] = tmp;
	        	}
	        	else
	        	{
	        		if (p[tmp] != pattern[idx] || w[pattern[idx]] != tmp)
	        			return false;
	        	}
	        	++idx;
        	}

        	i = j+1;
        }

        return (idx == pattern.length());
    }
};
