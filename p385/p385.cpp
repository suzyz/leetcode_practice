// The discription of the program seems ambiguous to me.

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        int n = s.length();

        if (n > 1 && s[0] >= '0' && s[0] <= '9')
        {
        	int d = 0, i = 0;
        	while (i < n)
        	{
        		if (s[i] < '0' || s[i] > '9')
        			break;
        		d = 10 * d + s[i] - '0';
        		++i;
        	}
        	NestedInteger res(d);

        	++i;
        	if (i < n-1)
        	{
        		string tmp = s.substr(i,n-2-i+1);
        		NestedInteger rest = deserialize(tmp);
        		res.add(rest);
        	}

        	return res;
        }
        else
        if (n > 1 && (s[0] == '[' && s[n-1] == ']'))
        {
        	string tmp = s.substr(1,n-2);
        	NestedInteger rest = deserialize(tmp);
        	NestedInteger res;
        	if (rest.isInteger())
        		res.add(rest.getInteger());
        	else
        		res.add(rest.getList());

        	return res;
        }
        else
        	return NestedInteger();
    }
};
