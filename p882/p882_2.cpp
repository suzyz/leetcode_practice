// Using Dijkstra to get all distances.
// Then think about all vertexes and all edges.
class Solution {
public:

    struct mycmp
    {
        bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        }   
    };

    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        
        vector<vector<pair<int, int>>> g(N);

        for (int i = 0; i < edges.size(); ++i) {
        	int u = edges[i][0], v = edges[i][1], w = edges[i][2] + 1;
        	g[u].push_back(make_pair(v, w));
        	g[v].push_back(make_pair(u, w));
        }

        vector<int> dist(N, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycmp> pq;

        dist[0] = 0;
        pq.push(make_pair(0, 0));

        while (!pq.empty()) {
        	int cur = pq.top().first, d = pq.top().second;
        	pq.pop();

            if (dist[cur] < d)
                continue;

        	for (int i = 0; i < g[cur].size(); ++i) {
        		int v = g[cur][i].first, newDist = d + g[cur][i].second;
        		if (newDist <= M)
        			if (dist[v] == -1 || dist[v] > newDist) {
        				dist[v] = newDist;
        				pq.push(make_pair(v, newDist));
        			}
        	}
        }

        int count = 0;
        for (int i = 0; i < N; ++i)
        	if (dist[i] != -1)
        		++count;
        
        for (int i = 0; i < edges.size(); ++i) {
        	int u = edges[i][0], v = edges[i][1], w = edges[i][2] + 1;
        	if (dist[u] == -1 && dist[v] == -1)
        		continue;
        	
        	if (dist[v] == -1)
        		count += M - dist[u];
        	else
        		if (dist[u] == -1)
        			count += M - dist[v];
        		else {
        			if (abs(dist[u] - dist[v]) == w)
        				count += w - 1;
        			else
        				count += min(w-1, M - dist[u] + M - dist[v]);
        		}
        }

        return count;
    }
};