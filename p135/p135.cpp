class Solution {
public:
    int candy(vector<int>& ratings) {
		int n = ratings.size();
		vector<int> left(n,0);

		for (int i = 1; i < n; ++i)
			if (ratings[i] > ratings[i-1])
				left[i] = left[i-1] + 1;

		int right = 0;
		int sum = 0;
		for (int i = n-1; i >= 0; --i)
		{
			if (i < n-1 && ratings[i] > ratings[i+1])
				++right;
			else
				right = 0;
			sum += max(right,left[i]) + 1;
		}

		return sum;
    }
};
