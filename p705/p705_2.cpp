// Using BST.
class MyHashSet {
public:
    struct Node {
        int k;
        Node *l, *r;

        Node() { l = r = NULL; }
        Node(int key) { k = key; l = r = NULL; }
    };
    
    Node *root;
    
    /** Initialize your data structure here. */
    MyHashSet() {
        root = new Node(-1);
    }
    
    void add(int key) {

        Node *p = root;
        while (p != NULL) {
            if (key == p->k)
                return;

            if (key > p->k) {
                if (p->r == NULL) {
                    p->r = new Node(key);
                    return;
                }

                p = p->r;
            } else {
                if (p->l == NULL) {
                    p->l = new Node(key);
                    return;
                }

                p = p->l;
            }
        }
    }
    
    void remove(int key) {

        int flag = 0;
        Node *p = root, *pre = root;

        while (p != NULL) {
            if (key == p->k) {
                if (p->l == NULL || p->r == NULL) {
                    Node *tmp = p->l == NULL ? p->r : p->l;

                    if (flag == 0)
                        pre->l = tmp;
                    else
                        pre->r = tmp;

                    return;
                }

                Node *l = p->l, *cur = p->r;

                delete(p);
                if (flag == 0)
                    pre->l = cur;
                else
                    pre->r = cur;

                if (l == NULL)
                    return;

                if (cur->l == NULL) {
                    cur->l = l;
                    return;
                }

                Node *rl = cur->l;
                cur->l = l;
                while (l != NULL) {
                    if (l->r == NULL) {
                        l->r = rl;
                        return;
                    }

                    l = l->r;
                }

                return;
            }

            pre = p;
            if (key > p->k) {
                p = p->r;
                flag = 1;
            }
            else {
                p = p->l;
                flag = 0;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        Node *p = root;

        while (p != NULL) {
            if (key == p->k)
                return true;

            if (key > p->k)
                p = p->r;
            else
                p = p->l;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */