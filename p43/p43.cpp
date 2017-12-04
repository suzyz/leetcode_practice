class Solution {
public:
    string multiply(string num1, string num2) {
    	if (num1 == "0" || num2 == "0")
    		return "0";

        int n = num1.size(), m = num2.size();
        if (m < n)
        	return multiply(num2,num1);

        vector<string> times(10,"");

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i = 0; i < num1.size(); ++i)
        	num1[i] -= '0';
        for (int i = 0; i < num2.size(); ++i)
        	num2[i] -= '0';

        string res = "";
        for (int i = 0; i < m; ++i)
        {
        	int k = num2[i];
        	if (k == 0)
        		continue;

        	if (times[k].size() == 0)
        		times[k] = multi(num1,k);

        	string cur = times[k];
        	cur.insert(0,i,0);
        	add(res,cur);
        }

        reverse(res.begin(), res.end());
        for (int i = 0; i < res.size(); ++i)
        	res[i] += '0';
        return res;
    }

    string multi(string a,int b)
    {
    	string c = a;
    	int carry = 0;
    	for (int i = 0; i < a.length(); ++i)
    	{
    		c[i] = a[i] * b + carry;
    		carry = c[i] / 10;
    		c[i] %= 10;
    	}

    	if (carry)
    		c.append(1,carry);

    	return c;
    }

    void add(string &a,string b)
    {
    	if (a.length() < b.length())
    	{
    		string c = a;
    		a = b;
    		b = c;
    	}

    	int carry = 0;
    	for (int i = 0; i < b.length(); ++i)
    	{
    		a[i] += b[i] + carry;
    		carry = a[i] / 10;
    		a[i] %= 10;
    	}

    	if (carry)
    	{
    		int i = b.length();
    		while (carry && i < a.length())
    		{
    			a[i] += carry;
    			if (a[i] > 9)
    			{
    				a[i] -= 10;
    				carry = 1;
    			}
    			else
    				carry = 0;
    			++i;
    		}

    		if (carry)
    			a.append(1,1);
    	}
    }
};
