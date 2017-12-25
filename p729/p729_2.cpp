// BST. O(N*logN)
class MyCalendar {
public:
	struct TreeNode
    {
        int st,en;
        TreeNode *l,*r;
        TreeNode() { st = en = 0; l = r = NULL; }
        TreeNode(int s,int e) { st = s; en = e; l = r = NULL; }
    };

    TreeNode *root = NULL;

    MyCalendar() {
        root = new TreeNode(-1,-1);
    }
    
    bool book(int start, int end) {
        return insert(root,start,end);
    }

    bool insert(TreeNode *cur,int st,int en)
    {
        if (cur == NULL)
            return false;

        if (st >= cur->en)
        {
            if (cur->r == NULL)
            {
                cur->r = new TreeNode(st,en);
                return true;
            }
            else
                return insert(cur->r,st,en);
        }
        else
        if (en <= cur->st)
        {
            if (cur->l == NULL)
            {
                cur->l = new TreeNode(st,en);
                return true;
            }
            else
                return insert(cur->l,st,en);
        }
        else
            return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
