
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/

const int maxn = 2002;

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();
        vector<Employee*> p(maxn, NULL);
        for (int i = 0; i < n; ++i)
       		p[employees[i]->id] = employees[i];

        return dfs(p, id);
    }

    int dfs(vector<Employee*> &p, int id) {
    	int res = p[id]->importance;

    	for (vector<int>::iterator it = p[id]->subordinates.begin(); it != p[id]->subordinates.end(); ++it)
    		res += dfs(p, *it);

    	return res;
    }
};
