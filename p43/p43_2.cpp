// Easier.

class Solution {
public:
    string multiply(string num1, string num2) {
    	if (num1 == "0" || num2 == "0")
    		return "0";

        int n = num1.size(), m = num2.size();
        vector<int> res(n+m,0);

        for (int i = 0; i < n; ++i)
            num1[i] -= '0';
        for (int i = 0; i < m; ++i)
            num2[i] -= '0';

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                res[n+m-2-i-j] += num1[i] * num2[j];

        for (int i = 0; i < n+m-1; ++i)
        {
            res[i+1] += res[i]/10;
            res[i] %= 10;
        }

        string s;

        int i = n+m-1;
        while (i > 0 && res[i] == 0)
            --i;

        while (i >= 0)
        {
            s += (char)('0' + res[i]);
            --i;
        }

        return s;
    }
};
