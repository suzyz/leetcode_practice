class Solution {
public:
    string validIPAddress(string s) {
        int n = s.length();

        if (n < 7 || n > 39)
        	return "Neither";

        int p1 = s.find('.'), p2 = s.find(':');
        if (p1 == string::npos && p2 == string::npos)
        	return "Neither";

        if (p1 != string::npos && p2 != string::npos)
        	return "Neither";

        if (p1 != string::npos) {
        	if (n > 19)
        		return "Neither";

        	int last = -1, count = 0;
        	while (true) {
        		++count;

        		p1 = s.find('.', last+1);
                // printf("count:%d p1:%d\n", count,p1);

        		string cur;
        		if (p1 == string::npos)
        			cur = s.substr(last+1);
        		else
        			cur = s.substr(last+1, p1-last-1);
        		
        		if (cur.length() == 0 || cur.length() > 3)
        			return "Neither";

        		int d = 0;
        		for (int j = 0; j < cur.length();++j)
        			if (!isdigit(cur[j]))
        				return "Neither";
        			else
        				d = 10*d + cur[j]-'0';
        		
        		if (d > 255 || (d == 0 && cur.length() > 1) || (d != 0 && cur[0] == '0'))
        			return "Neither";

        		if (p1 == string::npos)
        			break;
        		last = p1;
        	}

        	if (count != 4)
        		return "Neither";
        	else
        		return "IPv4";
        } else {
        	if (n < 15)
        		return "Neither";

        	int last = -1, count = 0;
        	while (true) {
        		++count;

        		p1 = s.find(':', last+1);

        		string cur;
        		if (p1 == string::npos)
        			cur = s.substr(last+1);
        		else
        			cur = s.substr(last+1, p1-last-1);
        		
        		if (cur.length() == 0 || cur.length() > 4)
        			return "Neither";

        		for (int j = 0; j < cur.length();++j)
        			if (!isdigit(cur[j])) {
                        if (cur[j] < 'A' || cur[j] > 'z' || (cur[j] > 'Z' && cur[j] < 'a'))
                            return "Neither";
                        
        				if (cur[j] >= 'a')
        					cur[j] = cur[j] - 'a' + 'A';

        				if (cur[j] > 'F')
        					return "Neither";
        			}

        		if (p1 == string::npos)
        			break;
        		last = p1;
        	}

        	if (count != 8)
        		return "Neither";
        	else
        		return "IPv6";
        }
    }
};