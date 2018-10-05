// brutal.

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
    	int n = A.length(), m = B.length();

    	if (m==0)
    		return 1;
    	if (n==0)
    		return -1;

    	int k = m/n;
    	if (m%n)
    		k++;
    	string s = A;
    	for (int i=1;i<k;i++)
    		s += A;

    	if (s.find(B) != string::npos)
    		return k;
    	
    	s += A;
     	if (s.find(B) != string::npos)
    		return k+1;
    	else
    		return -1;   	
    }
};