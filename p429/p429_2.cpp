// Using a queue and a vector.

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

        queue<Node*> qu;
        qu.push(root);

        int count = 1;
        vector<int> curLevel;

        while (!qu.empty()) {
        	Node* cur = qu.front();
            qu.pop();

            curLevel.push_back(cur->val);
            --count;

            for (int i = 0; i < cur->children.size(); ++i)
                qu.push(cur->children[i]);

            if (count == 0) {
                res.push_back(curLevel);

                count = qu.size();
                curLevel = vector<int>();
            }
        }

        return res;
    }
};