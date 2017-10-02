#include <cstdlib>
class Solution {
public:
    vector<string> fizzBuzz(int n) {
       	int three = 0, five = 0;
       	vector<string> ans;
       	for (int i = 1; i <= n; ++i)
       	{
       		three++;
       		five++;
       		if (three == 3)
       			three = 0;
       		if (five == 5)
       			five = 0;

       		if (!three && !five)
       			ans.push_back("FizzBuzz");
       		else
       		if (!three)
       			ans.push_back("Fizz");
       		else
       		if (!five)
       			ans.push_back("Buzz");
       		else
       			ans.push_back(to_string(i));
       	}
       	return ans;
    }
};