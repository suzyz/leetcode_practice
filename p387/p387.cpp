class Solution {
public:
    int firstUniqChar(string s) {
        int count[26];
        memset(count,0,sizeof(count));
        for (int i = 0; i < s.length(); ++i)
        	++count[s[i]-'a'];
        
        for (int i = 0; i < s.length(); ++i)
        	if (count[s[i]-'a'] == 1)
        		return i;

       	return -1;
    }
};
