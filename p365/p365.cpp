class Solution {
public:
    int gcd(int a, int b) {
        if (a % b == 0)
            return b;
        
        return gcd(b, a%b);
    }
    
    bool canMeasureWater(int x, int y, int z) {
        if (z > x+y)
            return false;
        
        if (x == 0 || y == 0)
            return z == x || z == y;
        
        int g = gcd(x, y);
        return z % g == 0;
    }
};