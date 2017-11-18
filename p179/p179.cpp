class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> s(n,"");
        for (int i = 0; i < n; ++i)
        	s[i] = to_string(nums[i]);

        sort(s.begin(),s.end(),my_cmp);

        string res;
        for (int i = 0; i < n; ++i)
        	res += s[i];

        while (res.length() > 1 && res[0] == '0')
        	res.erase(res.begin());
        return res;
    }

    static bool my_cmp(const string &a,const string &b)
    {
    	string c = a + b;
    	string d = b + a;
    	return c > d;
    }
};
