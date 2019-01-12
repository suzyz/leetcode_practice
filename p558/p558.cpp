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
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1 == NULL)
            return quadTree2;
        if (quadTree2 == NULL)
            return quadTree1;

        if (quadTree1->isLeaf)
            return quadTree1->val ? quadTree1 : quadTree2;
        
        if (quadTree2->isLeaf)
            return quadTree2->val ? quadTree2 : quadTree1;

        Node *a, *b, *c, *d;
        a = quadTree1->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        b = quadTree1->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        c = quadTree1->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        d = quadTree1->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);

        if (a->isLeaf && b->isLeaf && c->isLeaf && d->isLeaf && a->val == b->val && b->val == c->val && c->val == d->val) {
                quadTree1->isLeaf = true;
                quadTree1->val = a->val;
                quadTree1->topLeft = quadTree1->topRight = quadTree1->bottomRight = quadTree1->bottomLeft = NULL;

                delete a;
                delete b;
                delete c;
                delete d;
        } else
            quadTree1->val = false;

        return quadTree1;
    }
};