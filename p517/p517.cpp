// For i,
// lCount: 左边（0,...,i-1号）洗衣机需要通过i向i及其右边机器传递的衣服数
// rCount: 右边（i+1,...,n-1号）洗衣机需要通过i向i及其左边机器传递的衣服数

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0, n = machines.size();

        for (int i = 0; i < n; ++i)
        	sum += machines[i];

        if (sum%n > 0)
        	return -1;

        int average = sum/n, ans = 0, leftSum = 0, lCount = 0, rCount = 0;
        for (int i = 0; i < n; ++i) 
        {
       		lCount = leftSum - i * average;
            leftSum += machines[i];
       		rCount = sum - leftSum - (n-i-1) * average;
            
            // printf("%d:%d %d\n", i, lCount, rCount);

       		if (lCount > 0 && rCount > 0)
       			ans = max(ans, max(lCount, rCount));
       		else
       			if (lCount < 0 && rCount < 0)
       				ans = max(ans, -lCount-rCount);
       			else
       				ans = max(ans, max(abs(lCount), abs(rCount)));
        }

       	return ans;
    }
};