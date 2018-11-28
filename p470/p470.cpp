// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
	bool isFirst = true;
	vector<int> pos;
	
    int rand10() {
        if (isFirst) {
        	vector<vector<double>> f(11, vector<double>(71));
        	f[0][0] = 1;
        	for (int i = 1; i <= 10; ++i)
        		for (int j = i; j <= 7*i; ++j)
        			for (int k = 1; k <= 7 && k <= j; ++k)
        				f[i][j] += f[i-1][j-k] / 7;

        	double sum = 0, base = 0.1;
        	for (int j = 10; j <= 70; ++j) {
        		sum += f[10][j];
        		if (sum > base) {
        			pos.push_back(j);
        			base += 0.1;

        			printf("j:%d\n", j);
        		}
        	}
        }

        int s = 0;
        for (int i = 0; i < 10; ++i)
       		s += rand7();

       	for (int i = 0; i < pos.size(); ++i)
       		if (s < pos[i])
       			return i+1;

        return 0;
    }
};