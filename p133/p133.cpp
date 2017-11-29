/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 class Solution {
public:
    unordered_map<int, UndirectedGraphNode *> po;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)
            return NULL;
        clone_graph(node);
        return po[node->label];
    }
    void clone_graph(UndirectedGraphNode *node)
    {
        if (po.count(node->label))
            return;

        po[node->label] = new UndirectedGraphNode(node->label);
        for (int i = 0; i < node->neighbors.size(); ++i)
        {
            clone_graph(node->neighbors[i]);
            po[node->label]->neighbors.push_back(po[node->neighbors[i]->label]);
        }
    }
};
