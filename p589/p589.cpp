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
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (root == NULL)
        	return res;

        stack<Node*> st;
        st.push(root);

        while (!st.empty()) { 
        	Node *cur = st.top();
        	st.pop();

        	res.push_back(cur->val);

        	for (int i = cur->children.size()-1; i >= 0; --i)
        		st.push(cur->children[i]);
        }

        return res;
    }
};