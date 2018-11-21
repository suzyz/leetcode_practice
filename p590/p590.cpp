/*
// Definition for a Node.
class Node {
public:
    int val;
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
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (root == NULL)
        	return res;

       	stack<Node*> st;
        stack<int> idx;
        st.push(root);
        idx.push(0);

        while (!st.empty()) {
        	Node* cur = st.top();
        	int n = cur->children.size();

        	if (idx.top() < n) {
        		st.push(cur->children[idx.top()]);
        		++idx.top();

	        	idx.push(0);
        	} else {
        		res.push_back(cur->val);

        		st.pop();
        		idx.pop();
        	}
        }

        return res;
    }
};