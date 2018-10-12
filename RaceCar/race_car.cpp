class Solution {
public:
	int f[10002];
    int racecar(int target) {
        if (target == 0 || f[target] > 0)
        	return f[target];

        int k = floor(log2(target+1));
        if ((1<<k)-1 == target)
        {
        	f[target] = k;
            // cout << target << " " << k << endl;
        	return k;
        }

        f[target] = k + 2 + racecar((1<<(k+1))-1-target);
        for (int i = 0; i < k; ++i)
        	f[target] = min(f[target],
        		k + i + 2 + racecar(target - (1<<k) + (1<<i)));

        // cout << target << " " << f[target] << endl;
        return f[target];
    }
};