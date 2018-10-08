// The partial bubble sort in the first version is actually reversing the part.
// Because this part is already in ascending order.

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;

        while (n > 0) {
        	digits.push_back(n%10);
        	n /= 10;
        }

        int len = digits.size();

        if (len == 1)
        	return -1;

        for (int i = 1; i < len; ++i)
        	for (int j = 0; j < i; ++j)
        		if (digits[i] < digits[j]) {
        			long long ans = 0;
        			swap(digits[i], digits[j]);

        			reverse(digits.begin(), digits.begin()+i);

        			for (int k = len-1; k >= 0; --k)
        				ans = ans*10 + digits[k];

        			if (ans > INT_MAX)
        				return -1;
        			else
        				return ans;
        		}

        return -1;
    }
};