class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if (n < k)
        	return 0;

        int kk = k;
        vector<vector<int>> count(n+1,vector<int>(26,0));

        count[1][s[0]-'a'] = 1;
        for (int i = 2; i <= n; ++i)
       	{
       		count[i] = count[i-1];
       		++count[i][s[i-1]-'a'];
       	}

       	int maxl = 0;
       	for (int i = 1; i <= n; ++i)
       	{
       		if (i+maxl > n)
       			break;

       		for (int j = n; j >= i+maxl; --j)
       		{
       			bool flag = true;
       			for (int k = 0; k < 26; ++k)
       				if (count[j][k] - count[i-1][k] > 0 && count[j][k] - count[i-1][k] < kk)
       				{
       					flag = false;
       					break;
       				}
       			
       			if (flag)
       			{
       				maxl = j-i+1;
       				break;
       			}
       		}
       	}

       	return maxl;
    }
};
