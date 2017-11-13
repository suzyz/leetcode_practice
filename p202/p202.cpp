// Using hash table.

class Solution {
public:
    bool isHappy(int n) {
    	if (n <= 0)
    		return false;

        unordered_set<int> vis;

        while (true)
        {
        	int sum = 0,tmp;
        	while (n > 0)
        	{
        		tmp = n%10;
        		sum += tmp*tmp;
        		n/=10;
        	}
        	if (sum == 1)
        		return true;
        	if (vis.count(sum))
        		return false;

        	vis.insert(sum);
        	n = sum;
        }
        return false;
    }
};
