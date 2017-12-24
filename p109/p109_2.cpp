// Without using an auxiliary vector.
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
        ListNode *p = head;
        int len = 0;
        while (p != NULL)
        {
            ++len;
            p = p->next;
        }

        return convert(0,len-1,head);
    }

    TreeNode* convert(int st,int en,ListNode* &head)
    {
    	if (st > en)
    		return NULL;

    	int mid = st + ((en-st)>>1);
    	
        TreeNode *l = convert(st,mid-1,head);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        root->left = l;
        root->right = convert(mid+1,en,head);

    	return root;
    }
};
