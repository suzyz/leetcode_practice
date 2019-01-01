class Solution {
public:
    struct fraction {
        int numerator, denominator;
        
        fraction(int a, int b) { numerator = a; denominator = b; }
    };

    string fractionAddition(string expression) {
        
        int n = expression.length();
        if (n == 0)
        	return "";

        fraction res(0, 1);

        int pos = -1;
        while (pos < n) {
			
	        int last = pos;
	        pos = expression.find('/', last+1);
	        int a = atoi(expression.substr(last+1, pos-last-1).c_str());

	        last = pos;
            ++pos;
	        while (pos < n && isdigit(expression[pos]))
	        	++pos;

	        int b = atoi(expression.substr(last+1, pos-last-1).c_str());

	        fraction cur(a, b);
	        add(res, cur);
            
            if (pos == n)
                break;
            else
                --pos;
        }

        string s;
        s = to_string(res.numerator) + "/" + to_string(res.denominator);
        
        return s;
    }

    void add(fraction& a, fraction& b) {
    	if (b.numerator == 0)
    		return;
        if (a.numerator == 0) {
            a.numerator = b.numerator;
            a.denominator = b.denominator;
            return;
        }

        // printf("%d %d %d %d\n", a.numerator, a.denominator, b.numerator, b.denominator);
    	int g = gcd(a.denominator, b.denominator);
    	int d = a.denominator * b.denominator / g;
        
        // printf("g:%d d:%d\n", g, d);

    	int c = a.numerator * b.denominator / g + b.numerator * a.denominator / g;
        
        // cout << c << endl;

    	if (c == 0)
    		d = 1;
    	else {
    		g = abs(gcd(c, d));
    		c /= g;
    		d /= g;
    	}

    	a.numerator = c;
    	a.denominator = d;
    }

    int gcd(int a, int b) {
    	if (a%b == 0)
    		return b;
    	return gcd(b, a%b);
    }
};