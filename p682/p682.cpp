class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<long long> nums;

        int n = 0;
        long long sum = 0;
        for (int i = 0; i < ops.size(); ++i) {
        	if (ops[i] == "+") {
        		long long v = 0;
        		if (n > 0)
        			v += nums[n-1];
        		if (n > 1)
        			v += nums[n-2];

        		++n;
        		nums.push_back(v);

        		sum += v;
        	} else if (ops[i] == "C") {
        		if (n == 0)
        			continue;

        		sum -= nums[n-1];
        		--n;
        		nums.pop_back();
        	} else if (ops[i] == "D") {
        		if (n == 0)
        			continue;

        		long long v = nums[n-1]*2;
        		++n;
        		nums.push_back(v);

        		sum += v;
        	} else {
                int v = stoi(ops[i], NULL, 10);
                
                ++n;
        		nums.push_back(v);

        		sum += v;
            }
        }

        return sum;
    }
};