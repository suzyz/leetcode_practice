class Solution {
public:
    int fib(int n) {
        if (n < 2)
            return n;
        int a = 0, b = 1, c;
        
        --n;
        while (n > 0) {
            --n;
            c = a+b;
            a = b;
            b = c;
        }
        
        return c;
    }
};