#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    	if (root == NULL)
    		return "";
       	
        vector<TreeNode*> curLevelNodes;
        curLevelNodes.push_back(root);

        string s = to_string(root->val);

        while (!curLevelNodes.empty()) {

            vector<TreeNode*> nextLevelNodes;
            for (int i = 0; i < curLevelNodes.size(); ++i)
                if (curLevelNodes[i] != NULL)
                {
                    nextLevelNodes.push_back(curLevelNodes[i]->left);
                    nextLevelNodes.push_back(curLevelNodes[i]->right);
                }

            for (int i = 0; i < nextLevelNodes.size(); ++i)
            {
                if (nextLevelNodes[i] == NULL)
                    s += ",null";
                else
                    s += "," + to_string(nextLevelNodes[i]->val);
            }

            curLevelNodes = nextLevelNodes;
        } 
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0) {
            return NULL;
        }

        data += ",";

        TreeNode* root = new TreeNode(0);
        int pos = data.find(',');

        string tmp;
        tmp = data.substr(0, pos);
        root->val = atoi(tmp.c_str());

        vector<TreeNode*> curLevelNodes;
        curLevelNodes.push_back(root);

        while (!curLevelNodes.empty() && pos != string::npos) {
            vector<TreeNode*> nextLevelNodes;

            for (int i = 0; i < curLevelNodes.size(); ++i)
            {
                int new_pos = data.find(',', pos+1);
                if (new_pos == string::npos)
                    break;
                else {
                    tmp = data.substr(pos+1, new_pos-pos-1);
                    if (tmp != "null") {
                        curLevelNodes[i]->left = new TreeNode(atoi(tmp.c_str()));
                        nextLevelNodes.push_back(curLevelNodes[i]->left);
                    }
                }
                pos = new_pos;

                new_pos = data.find(',', pos+1);
                if (new_pos == string::npos)
                    break;
                else {
                    tmp = data.substr(pos+1, new_pos-pos-1);
                    if (tmp != "null") {
                        curLevelNodes[i]->right = new TreeNode(atoi(tmp.c_str()));
                        nextLevelNodes.push_back(curLevelNodes[i]->right);
                    }
                }
                pos = new_pos;
            }

            curLevelNodes = nextLevelNodes;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

void print_tree(TreeNode *root) {
    if (root == NULL)
        return;

    printf("%d:\n", root->val);
    if (root->left == NULL)
        printf("no left\n");
    else
        printf("left:%d\n", root->left->val);
    
    if (root->right == NULL)
        printf("no right\n");
    else
        printf("right:%d\n", root->right->val);

    print_tree(root->left);
    print_tree(root->right);
}


int main(int argc, char const *argv[])
{
    TreeNode root(2);
    root.left = new TreeNode(1);
    // root.left->left = new TreeNode(6);
    root.left->right = new TreeNode(7);
    // root.right = new TreeNode(3);
    // root.right->left = new TreeNode(4);
    // root.right->right = new TreeNode(5);

    Codec codec;
    string s = codec.serialize(&root);
    printf("%s\n", s.c_str());

    TreeNode* root2 = codec.deserialize(s);
    print_tree(root2);

    return 0;
}