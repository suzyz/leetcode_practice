#include <iostream>
#include <cstdio>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int countNodes(TreeNode* root) {
        int level = 0;
        TreeNode *p = root;
        while (p != NULL)
        {
        	++level;
        	p = p->left;
        }

        if (level < 2)
        	return level;

        int l = 1, r = (1<<(level-1));

        while(l < r)
        {
        	int mid = l + ((r-l)>>1) + 1;
        	if (check(root,level,mid))
        		l = mid;
        	else
        		r = mid-1;
        }

        int res = (1<<(level-1)) - 1 + l;
       	return res;
    }


    bool check(TreeNode *root,int level,int idx)
    {
    	int total = (1<<(level-1)), now = 1;
    	for (int i = 0; i < level-1; ++i)
    	{
    		if (root == NULL)
    			return false;

    		int left_sum = total/(1<<i) * (now-1) + (1<<(level-2-i));
    		//printf("i:%d now:%d left_sum:%d idx:%d\n",i,now,left_sum,idx);
    		if (idx > left_sum)
    		{
    			root = root->right;
    			now <<= 1;
    		//	printf("go right\n");
    		}
    		else
    		{
    			root = root->left;
    			now = (now<<1) - 1;
    		//	printf("go left\n");
    		}
    	}
    	return (root != NULL);
    }
};


int main()
{
	Solution s;
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(1);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(1);
	root->right->left = new TreeNode(1);
	cout << s.countNodes(root) << endl;
}