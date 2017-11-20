class Solution {
public:
    bool isNumber(string s) {
        
        // get rid of spaces.
        int n = s.length();
       	for (string::iterator i = s.begin(); i != s.end(); )
       	{
       		if (*i == ' ')
       			i = s.erase(i);
       		else
       			break;
       	}

       	n = s.length();
       	if (n == 0)
       		return false;

       	for (int i = n-1; i >= 0; --i)
       		if (s[i] == ' ')
       			s.erase(s.begin()+i);
       		else
       			break;

       	n = s.length();
       	if (n == 0)
       		return false;

       	// check for sign
       	if (s[0] == '-' || s[0] == '+')
       	{
       		s.erase(s.begin());
       		--n;
       		if (n == 0)
       			return false;
       	}

       	// check for non-number characters except 'e','.' and '+'/'-'
       	bool sign = false, num = false;
       	int pos_e = -1, pos_dot = -1;
       	for (int i = 0; i < n; ++i)
       		if (s[i] < '0' || s[i] > '9')
       		{
       			if (s[i] == 'e')
       			{
       				if (pos_e >= 0)
       					return false;

       				pos_e = i;
       				continue;
       			}
       			else
       			if (s[i] == '.')
       			{
       				if (pos_dot >= 0)
       					return false;

       				pos_dot = i;
       				continue;
       			}
       			else
       			if (s[i] == '-' || s[i] == '+')
       			{
       				if (pos_e >= 0 && i == pos_e + 1 && !sign)
       				{
       					sign = true;
       					continue;
       				}
       				else
       					return false;
       			}
       			return false;
       		}
       		else
       			num = true;

        // there should be numbers
       	if (!num)
       		return false;

       	// 'e' shouldn't be at the beginning or the end
       	if (pos_e == 0 || pos_e == n-1)
       		return false;

       	// the string shouldn't start with ".e"
       	if (pos_dot == 0 && pos_e == 1)
       		return false;

       	// 'e' shouldn't be before '.', if there is one.
       	if (pos_e >= 0 && pos_e < pos_dot)
       		return false;

       	// there should be numbers after '+'/'-'
       	if (sign)
       	{
       		--n;
       		if (pos_e == n-1)
       			return false;
       	}

       	return true;
    }
};
