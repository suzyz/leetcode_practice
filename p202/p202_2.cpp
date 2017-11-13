// Using two pointers.

class Solution {
public:
    bool isHappy(int n) {
    	if (n <= 0)
    		return false;

        int slow = digit_square(n);
        int fast = digit_square(slow);
        while (slow != fast)
        {
        	slow = digit_square(slow);
            fast = digit_square(digit_square(fast));
        }

        return (slow == 1);
    }

    int digit_square(int n)
    {
        int sum = 0,tmp;
        while (n > 0)
        {
            tmp = n%10;
            sum += tmp*tmp;
            n/=10;
        }
        return sum;
    }
};
