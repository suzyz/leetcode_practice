class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        if (n != s2.length())
        	return false;

        if (s1 == s2)
        	return true;

        vector<int> letters(260,0);
        for (int i = 0; i < n; ++i)
        {
        	++letters[s1[i]];
        	--letters[s2[i]];
        }

        for (int i = 0; i < 256; ++i)
       		if (letters[i] != 0)
       			return false;

       	for (int i = 1; i < n; ++i)
       	{
       		if (isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i,n-i),s2.substr(i,n-i)))
       			return true;

       		if (isScramble(s1.substr(0,i),s2.substr(n-i,i)) && isScramble(s1.substr(i,n-i),s2.substr(0,n-i)))
       			return true;
       	}
       		
       	return false;
    }
};
