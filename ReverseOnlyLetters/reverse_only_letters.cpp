class Solution {
public:
    string reverseOnlyLetters(string S) {
        int n = S.length();

        int i = 0, j = n-1;
        while (i < j) {
        	if (!isLetter(S[i])) {
        		++i;
        		continue;
        	}

        	if (!isLetter(S[j])) {
        		--j;
        		continue;
        	}

        	char tmp = S[i];
        	S[i] = S[j];
        	S[j] = tmp;

        	++i;
        	--j;
        }

        return S;
    }

    bool isLetter(char c) {
    	if (c >= 'a' && c <= 'z')
    		return true;
    	if (c >= 'A' && c <= 'Z')
    		return true;
    	return false;
    }
};