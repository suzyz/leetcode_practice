/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n==0)
        	return NULL;

        return build(nums,0,n-1);
    }

    TreeNode* build(vector<int>& nums,int l,int r)
    {
    	int mid = l + ((r-l)>>1);

    	TreeNode *p = new TreeNode(nums[mid]);
    	if (l < mid)
    		p->left = build(nums,l,mid-1);
    	if (mid < r)
    		p->right = build(nums,mid+1,r);
    	
    	return p;
    }
};
