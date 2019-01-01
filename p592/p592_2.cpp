// 
class Solution {
public:
    string fractionAddition(string expression) {
        
        int n = expression.length();
        if (n == 0)
            return "";

        int numerator = 0, denominator = 1;

        int pos = -1;
        while (pos < n-1) {
            
            int last = pos;
            pos = expression.find('/', last+1);
            int a = atoi(expression.substr(last+1, pos-last-1).c_str());

            last = pos;
            while (pos+1 < n && isdigit(expression[pos+1]))
                ++pos;

            int b = atoi(expression.substr(last+1, pos-last).c_str());
            
            numerator = a * denominator + numerator * b;
            denominator *= b;

            if (numerator != 0) {
                int g = gcd(abs(numerator), denominator);
                numerator /= g;
                denominator /= g;
            } else
                denominator = 1;
        }

        string s;
        s = to_string(numerator) + "/" + to_string(denominator);
        
        return s;
    }

    int gcd(int a, int b) {
        if (a%b == 0)
            return b;
        return gcd(b, a%b);
    }
};