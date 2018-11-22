// Using a stack.

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
	vector<vector<int>> res;

    vector<vector<int>> levelOrder(Node* root) {
    	if (root == NULL)
    		return res;

        stack<pair<Node*, int>> st;
        st.push(make_pair(root, 0));

        while (!st.empty()) {
        	pair<Node*, int> cur = st.top();
        	st.pop();

        	if (cur.second >= res.size())
        		res.push_back(vector<int>());

        	res[cur.second].push_back(cur.first->val);

        	for (int i = cur.first->children.size()-1; i >= 0; --i)
        		st.push(make_pair(cur.first->children[i], cur.second+1));
        }

        return res;
    }
};