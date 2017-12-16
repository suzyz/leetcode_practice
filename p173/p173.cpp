/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
	stack<TreeNode *> st;
    BSTIterator(TreeNode *root) {
    	while (root != NULL)
    	{
        	st.push(root);
        	root = root->left;
    	}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        if (!st.empty())
        {
	        TreeNode *p = st.top();
	        st.pop();

	        TreeNode *q = p->right;
	        while (q != NULL)
	        {
	        	st.push(q);
	        	q = q->left;
	        }

        	return p->val;
        }
        else
        	return 0;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
