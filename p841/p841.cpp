class Solution {
public:
	unordered_set<int> vis;

    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        visitRoom(0, rooms);

        return vis.size() == rooms.size();
    }

    void visitRoom(int cur, vector<vector<int>>& rooms) {
    	vis.insert(cur);

    	for (int i = 0; i < rooms[cur].size(); ++i) {
    		int v = rooms[cur][i];
    		if (!vis.count(v))
    			visitRoom(v, rooms);
    	}
    }
};