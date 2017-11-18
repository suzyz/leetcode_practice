class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        if (denominator == 0)
        	return res;

        long long n = numerator, d = denominator;

        if (n>0 && d<0)
        {
        	d *= -1;
        	res = "-";
        }
        else
        if (n<0 && d>0)
        {
        	n *= -1;
        	res = "-";
        }

        res += to_string(n/d);
        n %= d;
        if (n == 0)
        	return res;

        res += '.';
        unordered_map<int,int> pos;

        n *= 10;
        pos[n] = 0;
        int i = 0, base = res.length();
        while (n)
        {
        	++i;
        	res += (char)(n/d + '0');
        	n = n % d * 10;
        	if (pos.count(n))
        	{
        		res.insert(base+pos[n],"(");
        		res += ')';
        		break;
        	}
        	else
        		pos[n] = i;
        }
        return res;
    }
};
