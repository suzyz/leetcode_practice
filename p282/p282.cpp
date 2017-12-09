#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.length() == 0)
            return res;

        for (int i = 0; i < num.length(); ++i)
        {
            string tmp = num.substr(0,i+1);
            int k = stol(tmp); // stol() is in <string>
            if (to_string(k).length() != i+1)
                break;

            dfs(i+1,tmp,num,'#',k,k,target,res);
        }

        return res;
    }

    void dfs(int pos,string cur,string &num,char last_operator,int last_v,int cumulative_v,int target,vector<string> &res)
    {
    	if (pos == num.length() && cumulative_v == target)
            res.push_back(cur);
        else
        {
            for (int i = pos; i < num.length(); ++i)
            {
                string tmp = num.substr(pos,i-pos+1);
                int k = stol(tmp);
                if (to_string(k).length() != i-pos+1)
                    break;

                dfs(i+1,cur+"+"+tmp,num,'+',k,cumulative_v+k,target,res);
                dfs(i+1,cur+"-"+tmp,num,'-',k,cumulative_v-k,target,res);

                int new_v = last_operator == '+' ? cumulative_v-last_v+last_v*k
                            : last_operator == '-' ? cumulative_v+last_v-last_v*k
                            : last_v*k;
                dfs(i+1,cur+"*"+tmp,num,last_operator,last_v*k,new_v,target,res);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
   // vector<string> res = s.addOperators("00",0);
   // vector<string> res = s.addOperators("123",6);
   // vector<string> res = s.addOperators("123456789",45);
    vector<string> res = s.addOperators("12345",30);

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << endl;
    }
    return 0;
}
