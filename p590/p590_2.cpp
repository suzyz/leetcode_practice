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

        st.push(root);

        while (!st.empty()) {
        	Node* cur = st.top();
            st.pop();

            res.push_back(cur->val);

        	int n = cur->children.size();
            for (int i = 0; i < n; ++i)
                st.push(cur->children[i]);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};