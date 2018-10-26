// Shorter code. The memorization in search is removed, but a few checkups before the DFS are added to prevent TLE.
class Solution {
public:
    int n;
    bool success = false;

    bool canCross(vector<int>& stones) {
        n = stones.size();

        for (int i = 1; i < n; ++i)
            if (stones[i] - stones[i-1] > i)
                return false;

        unordered_set<int> pos(stones.begin(), stones.end());
        
        dfs(1, 1, stones[n-1], pos);

        return success;
    }

    void dfs(int curPos, int lastStep, int target, unordered_set<int>& pos) {
        if (curPos >= target)
        {
            success = curPos == target;
            return;
        }

        for (int i = 1; i >= -1; --i)
        {
            if (lastStep + i <= 0)
                break;

            int nextPos = curPos + lastStep + i;
            if (pos.count(nextPos))
            {
                dfs(nextPos, lastStep + i, target, pos);
                if (success)
                    return;
            }
        }
    }
};
