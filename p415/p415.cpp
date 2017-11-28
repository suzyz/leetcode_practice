class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.length(), m = num2.length();
        if (n < m)
        	return addStrings(num2,num1);

        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());

        int carry = 0;
        for (int i = 0; i < m; ++i)
        {
        	num1[i] = num1[i] - '0' + num2[i]-'0' + carry;
        	if (num1[i] > 9)
        	{
        		carry = 1;
        		num1[i] -= 10;
        	}
        	else
        		carry = 0;

        	num1[i] += '0';
        }

        int i = m;
        while (carry && i < n)
        {
        	num1[i] = num1[i] - '0' + carry;
        	if (num1[i] > 9)
        		num1[i] -= 10;
        	else
        		carry = 0;

        	num1[i] += '0';
        	++i;
        }

        if (carry)
        	num1 += "1";

        reverse(num1.begin(),num1.end());
        return num1;
    }
};
