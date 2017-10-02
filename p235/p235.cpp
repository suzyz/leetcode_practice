#include <iostream>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  	    if (root == NULL || p == NULL || q == NULL)
  	      	return NULL;
  	    if (root->val > p->val && root->val > q->val)
  	    	return lowestCommonAncestor(root->left,p,q);
  	    if (root->val < p->val && root->val < q->val)
  	    	return lowestCommonAncestor(root->right,p,q);
  	    return root;
    }
};

int main(int argc, char const *argv[])
{
	
	return 0;
}