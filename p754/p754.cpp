class Solution {
public:
    int reachNumber(int target) {

    	if (target == 0)
    		return 0;
    	if (target < 0)
    		target = -target;

        int sum = 0, i = 0;
        while (sum < target) {
        	++i;
        	sum += i;
        }

        if (sum == target)
        	return i;

        sum -= target;
        if ((sum&1) == 0)
        	return i;

        if ((i+1)&1)
        	return i+1;
        else
        	return i+2;
    }
};