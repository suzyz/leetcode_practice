// Use an auxiliary vector.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while (head != NULL)
        {
        	nums.push_back(head->val);
        	head = head->next;
        }

        return convert(0,nums.size()-1,nums);
    }

    TreeNode* convert(int st,int en,vector<int> &nums)
    {
    	if (st > en)
    		return NULL;
    	if (st == en)
    	{
    		TreeNode *root = new TreeNode(nums[st]);
    		return root;
    	}

    	int mid = st + ((en-st)>>1);
    	TreeNode *root = new TreeNode(nums[mid]);
    	root->left = convert(st,mid-1,nums);
    	root->right = convert(mid+1,en,nums);

    	return root;
    }
};
