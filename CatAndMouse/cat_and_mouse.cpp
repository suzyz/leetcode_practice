const int maxn = 52;

class Solution {
public:
	int color[maxn][maxn][3], degree[maxn][maxn][3];
	const int CAT = 2, MOUSE = 1, DRAW = 0;

	struct node
	{
		int mouse, cat, turn;

		node(int m, int c, int t) {
			mouse = m;
			cat = c;
			turn = t;
		}
	};

    int catMouseGame(vector<vector<int>>& graph) {

    	memset(degree, 0, sizeof(degree));
    	memset(color, 0, sizeof(color));

        int n = graph.size();

        for (int i = 0; i < n; ++i)
        	for (int j = 0; j < n; ++j)
        	{
        		degree[i][j][MOUSE] = graph[i].size();
        		degree[i][j][CAT] = graph[j].size();

        		for (int k = 0; k < graph[j].size(); ++k)
        			if (graph[j][k] == 0) {
        				--degree[i][j][CAT];
        				break;
        			}
        	}
        

        queue<node> qu;

        for (int i = 0; i < n; ++i)
        {
        	color[0][i][MOUSE] = color[0][i][CAT] = MOUSE;
        	qu.push(node(0, i, MOUSE));
        	qu.push(node(0, i, CAT));

        	if (i != 0) {
        		color[i][i][MOUSE] = color[i][i][CAT] = CAT;
        		qu.push(node(i, i, MOUSE));
        		qu.push(node(i, i, CAT));
        	}
        }
        
		
		while(!qu.empty()) {
			node cur = qu.front();
			qu.pop();

			int m1 = cur.mouse, c1 = cur.cat, t1 = cur.turn;
			int curRes = color[m1][c1][t1];
            
			vector<node> parent;
			getParents(m1, c1, t1, parent, graph);
            

			for (int i = 0; i < parent.size(); ++i) {
				int m2 = parent[i].mouse, c2 = parent[i].cat, t2 = parent[i].turn;
                
				if (color[m2][c2][t2] == DRAW) {
                    
					if (t2 == curRes) {
						color[m2][c2][t2] = curRes;

						qu.push(node(m2, c2, t2));

					} else {

						--degree[m2][c2][t2];
						if (degree[m2][c2][t2] == 0) {
							color[m2][c2][t2] = 3 - t2;

							qu.push(node(m2, c2, t2));
						}
					}
				}
			}
		}
        
        return color[1][2][MOUSE];
    }

    void getParents(int m, int c, int t, vector<node> &parent,
    	vector<vector<int>>& graph) {

    	if (t == CAT)
	    	for (int i = 0; i < graph[m].size(); ++i)
	    		parent.push_back(node(graph[m][i], c, 3-t));
	    else
	    	for (int i = 0; i < graph[c].size(); ++i)
	    		if (graph[c][i] != 0)
	    			parent.push_back(node(m, graph[c][i], 3-t));
    }
};