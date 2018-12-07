// Trie.
class Solution {
public:

    struct Node
    {
        Node *next[2];

        Node() { next[0] = next[1] = NULL; }
    };

    Node *root;
    const int maxLen = 31;

    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        root = new Node();

        for (int i = 0; i < n; ++i)
        {
            vector<int> digits(maxLen);
            int j = maxLen-1, tmp = nums[i];
            while (tmp > 0) {
                digits[j] = tmp&1;
                tmp >>= 1;

                --j;
            }

            if (i > 0)
                ans = max(ans, findMax(digits));

            insert(digits);
        }

        return ans;
    }

    int findMax(vector<int>& digits) {
        int res = 0;
        Node *p = root;

        for (int i = 0; i < digits.size(); ++i) {
            if (p->next[1 - digits[i]] == NULL)
                p = p->next[digits[i]];
            else {
                p = p->next[1 - digits[i]];
                res += 1 << (maxLen-1-i);
            }
        }

        return res;
    }

    void insert(vector<int>& digits) {
        Node *p = root;

        for (int i = 0; i < digits.size(); ++i)
        {
            if (p->next[digits[i]] == NULL)
                p->next[digits[i]] = new Node();

            p = p->next[digits[i]];
        }
    }
};