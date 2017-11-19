// Heap

class Solution {
public:
    struct Tuple
    {
        int x,y,val;
        Tuple(int a,int b,int c)
        {
            x = a; y = b; val = c;
        }
    };

    class mycomparison
    {
    public:
        bool operator() (const Tuple &a,const Tuple &b) const
        {
            return a.val > b.val;
        }
    };

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if (n == 0)
        	return 0;

        priority_queue<Tuple,vector<Tuple>,mycomparison> h;
        for (int i = 0; i < n; ++i)
            h.push(Tuple(0,i,matrix[0][i]));

        for (int i = 0; i < k-1; ++i)
        {
            Tuple tmp = h.top();
            h.pop();

            if (tmp.x == n-1)
                continue;

            h.emplace(tmp.x+1,tmp.y,matrix[tmp.x+1][tmp.y]);
        }

       	return h.top().val;
    }
};
