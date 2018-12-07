// Trie.
// Cleaner code.

class Solution {
public:

    struct Node
    {
        Node *l, *r;

        Node() { l = r = NULL; }
    };

    Node *root;
    const int maxLen = 31;

    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        root = new Node();

        for (int i = 0; i < n; ++i)
            insert(nums[i]);
        
        for (int i = 1; i < n; ++i)
            ans = max(ans, findMax(nums[i]));

        return ans;
    }

    int findMax(int v) {
        int w = 0;
        Node *p = root;

        for (int i = 0; i < maxLen; ++i) {
            int d = (1<<(maxLen-1-i)) & v;
            if ((d != 0 && p->l == NULL) || (d == 0 && p->r != NULL)) {
                p = p->r;
                w |= (1<<(maxLen-1-i));
            } else
                p = p->l;
        }

        return v ^ w;
    }

    void insert(int v) {
        Node *p = root;

        for (int i = 0; i < maxLen; ++i)
        {
            int d = (1<<(maxLen-1-i)) & v;
            if (d == 0) {
                if (p->l == NULL)
                    p->l = new Node();

                p = p->l;
            } else {
                if (p->r == NULL)
                    p->r = new Node();

                p = p->r;
            }
        }
    }
};