class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        if (n == 0)
        	return 0;

        stack<int> nums;
        for (int i = 0; i < n; ++i)
        {
        	int k;
        	if (is_num(tokens[i],k))
        		nums.push(k);
        	else
        	{
        		if (nums.size() < 2)
        				return 0;
        		int b = nums.top();
        		nums.pop();
        		int a = nums.top();
        		nums.pop();

        		switch (tokens[i][0])
        		{
        			case '+':
        				nums.push(a+b);
        				break;
        			case '-':
        				nums.push(a-b);
        				break;
        			case '*':
        				nums.push(a*b);
        				break;
        			case '/':
        				if (b == 0)
        					return 0;
        				nums.push(a/b);
        		}
        	}
        }
        return nums.top();
    }

    bool is_num(string s,int &res)
    {
    	if (s.length() == 0)
    		return false;

    	bool is_negative = false;
    	if (s[0] == '-')
    	{
    		is_negative = true;
    		s.erase(s.begin());
    		if (s.length() == 0)
    			return false;
    	}
    	else
    	if (s[0] < '0' || s[0] > '9')
    		return false;

    	res = 0;
    	for (int i = 0; i < s.length(); ++i)
    	{
    		if (s[i] < '0' || s[i] > '9')
    			return false;

    		res = 10 * res + s[i]-'0';
    	}
    	if (is_negative)
    		res *= -1;
    	return true;
    }
};
