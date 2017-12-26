class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        int i = 0;
        while (i < n)
        {
        	if (s[i] == '[')
        		break;
        	else
        		++i;
        }

        if (i >= n)
        	return s;

        int j = i+1, acc = 1;
        while (j < n)
        {
        	if (s[j] == '[')
        		++acc;
        	else
        	if (s[j] == ']')
        	{
        		--acc;
        		if (acc == 0)
        			break;
        	}
        	
        	++j;
        }

        string s2 = decodeString(s.substr(i+1,j-1-i));
        string s3;
        if (j+1 < n)
        	s3 = decodeString(s.substr(j+1,n-1-j));

        int times = 0, k = i-1, w = 1;
        while (k >= 0 && s[k] >= '0' && s[k] <= '9')
        {
        	times += w * (s[k]-'0');
        	--k;
        	w *= 10;
        }

        string res = s.substr(0,k+1);
        if (times == 0)
        	times = 1;
        for (int i = 0; i < times; ++i)
       		res += s2;
       	res += s3;
       	return res;
    }
};
