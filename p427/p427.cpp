/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0)
            return NULL;

        return constructTree(0, n, 0, n, grid);
    }

    Node* constructTree(int x1, int x2, int y1, int y2, vector<vector<int>>& grid) {
        Node *p = new Node();

        bool ok = true;
        for (int i = x1; i < x2 && ok; ++i)
            for (int j = y1; j < y2; ++j)
                if (grid[i][j] != grid[x1][y1]) {
                    ok = false;
                    break;
                }

        p->isLeaf = ok;

        if (ok) {
            p->val = grid[x1][y1] != 0;
            p->topLeft = p->topRight = p->bottomLeft = p->bottomRight = NULL;
        } else {
            p->val = true;
            int mid1 = (x1+x2)>>1, mid2 = (y1+y2)>>1;
            p->topLeft = constructTree(x1, mid1, y1, mid2, grid);
            p->topRight = constructTree(x1, mid1, mid2, y2, grid);
            p->bottomLeft = constructTree(mid1, x2, y1, mid2, grid);
            p->bottomRight = constructTree(mid1, x2, mid2, y2, grid);
        }

        return p;
    }
};