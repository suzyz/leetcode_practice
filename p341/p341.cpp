/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
	vector<NestedInteger> &nested_list = new vector<NestedInteger>();
	vector<NestedInteger>::iterator it;

	bool valid_son = false;
	NestedIterator &son = new NestedIterator(vector<NestedInteger>());

    NestedIterator(vector<NestedInteger> &nestedList) {
        nested_list = nestedList;
        it = nested_list.begin();
    }

    int next() {
        if (it->isInteger())
        {
        	int v = it->getInteger();
        	++it;
        	return v;
        }
        else
        {
        	if (!valid_son)
        	{
        		valid_son = true;
        		son = new NestedIterator(it->getList());
        	}
        	
        	if (son.hasNext())
        		return son.next();
        	else
        	{
        		++it;
        		valid_son = false;
        		return next();
        	}
        }
    }

    bool hasNext() {
        if (it == nested_list.end())
        	return false;

        if (it->isInteger())
        	return true;
        if (valid_son && son.hasNext())
        	return true;

        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
