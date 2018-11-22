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
    int maxDepth(Node* root) {
        if (root == NULL)
        	return 0;

        int ans = 0, curLevelCount = 1;
        queue<Node*> qu;
        qu.push(root);

        while (!qu.empty()) {
        	++ans;
        	int curLevelCount = qu.size();

        	while (curLevelCount) {
        		--curLevelCount;

				Node* cur = qu.front();
	        	qu.pop();

	        	for (int i = 0; i < cur->children.size(); ++i)
	        		qu.push(cur->children[i]);
        	}
        }

        return ans;
    }
};