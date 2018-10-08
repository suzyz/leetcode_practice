/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    TreeNode *treeRoot;
    queue<TreeNode*> nodes;

    CBTInserter(TreeNode* root) {
        treeRoot = root;

        bfs();

        while (!nodes.empty() && nodes.front()->right != NULL)
            nodes.pop();
    }

    void bfs() {
        queue<TreeNode*> qu;

        qu.push(treeRoot);
        while (!qu.empty()) {
            TreeNode *cur = qu.front();
            qu.pop();

            nodes.push(cur);
            if (cur->left != NULL)
                qu.push(cur->left);
            if (cur->right != NULL)
                qu.push(cur->right);
        }
    }
    
    int insert(int v) {
        TreeNode *parent = nodes.front();
        TreeNode *cur = new TreeNode(v);

        if (parent->left == NULL)
            parent->left = cur;
        else {
            parent->right = cur;
            nodes.pop();
        }

        nodes.push(cur);
        return parent->val;
    }
    
    TreeNode* get_root() {
        return treeRoot;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */