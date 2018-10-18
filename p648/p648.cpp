// Trie.

// Mind the string operations. 
// s.find(' ', start_pos);

class Solution {
public:
	struct node
	{
		bool isWord;
		node* nxt[26];

		node() { isWord = false; memset(nxt, 0, sizeof(nxt)); }
	};

	node *root;

    string replaceWords(vector<string>& dict, string sentence) {
        root = new node();

        for (int i = 0; i < dict.size(); ++i)
        	insert(dict[i]);

        string ans;
        int pos = -1;
        
        while (true) {
        	int newPos = sentence.find(' ', pos+1);
        	if (newPos == string::npos)
        	{
        		ans += replace(sentence.substr(pos+1));
        		break;
        	}

        	ans += replace(sentence.substr(pos+1, newPos - pos - 1));
        	ans += ' ';

        	pos = newPos;
        }

        return ans;
    }

    void insert(string& s) {
    	node *p = root;

    	for (int i = 0; i < s.length(); ++i)
    	{
    		int cur = s[i]-'a';
    		if (p->nxt[cur] == NULL)
    			p->nxt[cur] = new node();

    		p = p->nxt[cur];
    	}

    	p->isWord = true;
    }

    string replace(string w) {
    	node *p = root;
    	for (int i = 0; i < w.length(); ++i)
    	{
    		if (p->isWord)
    			return w.substr(0, i);

    		int cur = w[i]-'a';
    		if (p->nxt[cur] == NULL)
    			return w;

    		p = p->nxt[cur];
    	}

    	return w;
    }
};