class Solution {
public:
    int compress(vector<char>& chars) {
    	int n = chars.size(), i = 0, tot = 0;
        while (i < n) {
        	int j = i+1;
        	while (j < n && chars[j] == chars[i])
        		++j;

        	int count = j-i;
        	int len = calcLength(count);

        	chars[tot] = chars[i];
        	if (count > 1) {
        		int tmp = count;
        		for (int k = len; k > 0; --k)
        		{
        			chars[tot+k] = tmp%10 + '0';
        			tmp /= 10;
        		}
        	}

        	tot += 1 + len;
        	i = j;
        }

        return tot;
    }

    int calcLength(int count) {
    	if (count == 1)
    		return 0;
    	if (count < 10)
    		return 1;
    	if (count < 100)
    		return 2;
    	if (count < 1000)
    		return 3;

    	return 4;
    }
};