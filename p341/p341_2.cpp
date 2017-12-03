// Flatten the nested list and put the result in a vector at the beginning.

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
private:
    int idx = 0;
    vector<int> nums;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }

    void flatten(vector<NestedInteger> &nestedList)
    {
        for (int i = 0; i < nestedList.size(); ++i)
            if (nestedList[i].isInteger())
                nums.push_back(nestedList[i].getInteger());
            else
                flatten(nestedList[i].getList());
    }

    int next() {
       return nums[idx++];
    }

    bool hasNext() {
        return idx < nums.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
