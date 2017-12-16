class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0)
        	return false;

        while (num > 1 && (num&1) == 0)
        	num >>= 1;

        if (num == 1)
        	return true;

        while (num > 1 && num%5 == 0)
        	num /= 5;

        if (num == 1)
        	return true;

        while (num > 1 && num%3 == 0)
        	num /= 3;

        return num == 1;
    }
};
