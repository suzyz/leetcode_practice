class Solution {
public:
	struct Node
	{
		int v,sum;
		Node *left,*right;
		Node() { left = right = NULL; v = sum = 0; }
		Node(int _v,int _sum) { v = _v; sum = _sum; left = right = NULL; }
	};

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
        	return vector<int>();

        Node *root = new Node(nums[n-1],0);
        vector<int> res(n,0);

        for (int i = n-2; i >= 0; --i)
        	res[i] = insert(root,nums[i]);
        return res;
    }

    int insert(Node *cur,int v)
    {
    	++cur->sum;
    	if (v <= cur->v)
    	{
    		if (cur->left == NULL)
    		{
    			cur->left = new Node(v,1);
    			return 0;
    		}
    		else
    			return insert(cur->left,v);
    	}
    	else
    	{
    		int smaller = cur->left == NULL ? 1 : cur->left->sum + 1;

    		if (cur->right == NULL)
    		{
    			cur->right = new Node(v,1);
    			return smaller;
    		}
    		else
    			return insert(cur->right,v) + smaller;
    	}
    }
};
