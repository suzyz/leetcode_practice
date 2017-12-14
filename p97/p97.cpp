class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len1 + len2 != len3)
        	return false;

        bool f[len3+2][len1+2];
        memset(f,0,sizeof(f));
        f[0][0] = true;

        for (int i = 1; i <= len3; ++i)
        {
        	bool flag = false;
        	for (int j = max(0,i-len2); j <= min(i,len1); ++j)
        	{
        		if (f[i-1][j] && s2[i-j-1] == s3[i-1])
        			f[i][j] = flag = true;
        		else
        		{
	        		if (j > 0)
	        			if (f[i-1][j-1] && s1[j-1] == s3[i-1])
	        				f[i][j] = flag = true;        			
        		}
        	}
        	
        	if (!flag)
        		return false;
        }

        return true;
    }
};
