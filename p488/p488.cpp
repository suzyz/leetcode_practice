class Solution {
public:
    string board2;

    int plan[6];
    vector<char> ch;
    vector<int> maxCount;

    int findMinStep(string board, string hand) {
        int n = board.size(), m = hand.size();
        unordered_map<char, int> c1, c2;
        for (int i = 0; i < n; ++i)
            ++c1[board[i]];
        
        for (int i = 0; i < m; ++i)
            ++c2[hand[i]];
        
        for (unordered_map<char, int>:: iterator it = c2.begin();
                it != c2.end(); ++it) {
            if (c1[it->first] > 0)
            {
                ch.push_back(it->first);
                maxCount.push_back(it->second);   
            }
        }

        board2 = board;
        for (int i = 1; i <= m; ++i)
        {
            // printf("lim:%d\n", i);
            if (dfs1(0, 0, i))
                return i;
        }

        return -1;
    }

    bool dfs1(int cur, int sum, int lim) {
        if (cur == ch.size() - 1)
        {
            if (lim - sum > maxCount[cur])
                return false;

            plan[cur] = lim - sum;
            string curHand;
            for (int i = 0; i < ch.size(); ++i)
                if (plan[i] > 0)
                     curHand += string(plan[i], ch[i]);
            
//             for (int i = 0; i < ch.size(); ++i)
//                 printf("%c:%d\n", ch[i], plan[i]);
            // cout << "curHand:" << curHand << endl;
            
            return dfs2(board2, curHand);
        }
        
        for (int i = 0; i <= maxCount[cur] && i <= lim - sum; ++i) {
            plan[cur] = i;
            if (dfs1(cur+1, sum + i, lim))
                return true;
        }
        return false;
    }

    bool dfs2(string curBoard, string curHand) {

        while (true) {
            string t = shrink(curBoard);
            if (t == curBoard)
                break;
            
            curBoard = t;
        }
        // cout << curBoard << " " << curHand << endl;
        
        if (curBoard == "")
            return true;

        if (curHand == "")
            return false;

        for (int i = 0; i < curHand.length(); ++i)
        {
            int num1 = 1;
            if (i+1 < curHand.length() && curHand[i+1] == curHand[i])
                ++num1;

            for (int j = 0; j < curBoard.length(); ++j)
                if (curHand[i] == curBoard[j])
                {
                    int num2 = 1;
                    if (j+1 < curBoard.length() && curBoard[j+1] == curBoard[j])
                        ++num2;

                    if (num1 + num2 < 3)
                        continue;

                    int tmp1 = num1;
                    if (num1 + num2 == 4)
                        tmp1 = 1;
                    
                    string newHand = curHand;
                    newHand.erase(i, tmp1);
                    string newBoard = curBoard;
                    newBoard.erase(j, num2);
                    if (dfs2(newBoard, newHand))
                        return true;
                    
                    if (num2 > 1)
                        ++j;
                }
            
            if (num1 > 1)
                ++i;
        }

        return false;
    }

    string shrink(string s) {
        int i = 0;
        string res;
        while (i < s.length()) {
            int j = i+1;
            while (j < s.length() && s[j] == s[i])
                ++j;

            if (j-i < 3)
                res += string(j-i, s[i]);

            i = j;
        }

        return res;
    }
};