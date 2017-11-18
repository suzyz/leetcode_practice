class Trie {
public:
    struct Node
    {
        bool is_word;
        Node *p[26];
        Node() { is_word = false; memset(p,0,sizeof(p)); }
    };

    Node *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *p = root;
        int idx = 0;
        while (p && idx < word.length())
        {
            char c = word[idx];
            if (p->p[c-'a'] == NULL)
                p->p[c-'a'] = new Node();

            ++idx;
            p = p->p[c-'a'];
        }

        p->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *p = root;
        int idx = 0;
        while (p && idx < word.length())
        {
            char c = word[idx];
            if (p->p[c-'a'] == NULL)
                return false;

            ++idx;
            p = p->p[c-'a'];
        }

        if (p == NULL || p->is_word == false)
            return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *p = root;
        int idx = 0;
        while (p && idx < prefix.length())
        {
            char c = prefix[idx];
            if (p->p[c-'a'] == NULL)
                return false;

            ++idx;
            p = p->p[c-'a'];
        }

        return p != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
