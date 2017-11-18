#include <iostream>
#include <unordered_map>
using namespace std;

// without using STL's list container.

class LRUCache {
public:
    struct Node
    {
        int key,val;
        Node *pre,*next;
        Node() { pre = next = NULL; }
        Node(int k,int v) { key = k; val = v; pre = next = NULL; }
    };

	int cap, size;
    Node *head, *tail;
	unordered_map<int,Node *> pos;

    LRUCache(int capacity) {
        size = 0;
        cap = capacity;
        head = tail = NULL;
    }
    
    int get(int key) {

        if (!pos.count(key))
        	return -1;
        else
        {
        	int v = pos[key]->val;
        	put(key,v);
        	return v;
        }
    }
    
    void put(int key, int value) {
        if (pos.count(key))
        {
            --size;
            remove(pos[key]);
            pos.erase(key);
           
        }
        else
	        if (size >= cap)
	        {
                --size;
                int v = tail->key;
                remove(tail);
                
                pos.erase(v);
	        }

        ++size;

        Node *tmp = head;
        head = new Node(key,value);
        head->next = tmp;
        if (tmp != NULL)
            tmp->pre = head;

        if (tail == NULL)
            tail = head;

        pos[key] = head;
    }

    void remove(Node *cur)
    {
        // printf("cur is null\n");
        if (cur == NULL)
            return;
        // printf("cur:%d %d\n", cur->key,cur->val);

        if (cur == head)
        {
            if (cur == tail)
                head = tail = NULL;
            else
            {
                head = head->next;
                if (head != NULL)
                    head->pre = NULL;
            }
        }
        else
        if (cur == tail)
        {
            tail = tail->pre;
            if (tail != NULL)
                tail->next = NULL;
        }
        else
        {
            Node *l = cur->pre, *r = cur->next;
            l->next = r;
            r->pre = l;
        }

        delete cur;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main(int argc, char const *argv[])
{
    LRUCache cache(1);
    cache.put(2,1);
    cout<< "get(2):"<< cache.get(2) << endl;
    cache.put(3,2);
    cout<< "get(2):"<< cache.get(2) << endl;
    cout<< "get(3):"<< cache.get(3) << endl;

    return 0;
}
