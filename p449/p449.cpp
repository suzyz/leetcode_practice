/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serializeHelper(root, s);

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	if (data.length() == 0)
    		return NULL;
        
        vector<int> nums;
        int pos = -1;
        string tmp;

        while (true) {
			int new_pos = data.find(',', pos + 1);
			if (new_pos == string::npos)
				break;

			tmp = data.substr(pos+1, new_pos-pos-1);
			nums.push_back(atoi(tmp.c_str()));

			pos = new_pos;
        }

        TreeNode* root = NULL;
        deserializeHelper(0, nums.size()-1, nums, root);
        return root;
    }

    // pre-order traversal
    void serializeHelper(TreeNode *cur, string &s) {
    	if (cur == NULL)
    		return;

    	s += to_string(cur->val) + ",";

    	serializeHelper(cur->left, s);
    	serializeHelper(cur->right, s);
    }

    void deserializeHelper(int l, int r, vector<int> &nums, TreeNode* &root) {
    	if (l > r) {
    		root = NULL;
    		return;
    	}

    	root = new TreeNode(nums[l]);
    	if (l == r) {
    		return;
    	}

    	int k = l+1;
    	while (k <= r && nums[k] < nums[l])
    		k++;

    	deserializeHelper(l+1, k-1, nums, root->left);
    	deserializeHelper(k, r, nums, root->right);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));