class RLEIterator {
public:

	int pos, tot;
	std::vector<int> d;

    RLEIterator(vector<int> A) {
        pos = 0;
        for (int i = 0; i < A.size(); i+=2)
        {
        	if (A[i] > 0) {
        		d.push_back(A[i]);
        		d.push_back(A[i+1]);
        	}
        }
        tot = d.size();
    }
    
    int next(int n) {
        printf("n:%d\n",n);
        if (pos >= tot) {
        	return -1;
        }

        int sum = 0, res = -1;
        while (pos < tot && sum < n) {
             // printf("%d %d\n", pos, sum);
        	if (sum + d[pos] == n) {
        		res = d[pos+1];
                d[pos] = 0;
        		pos+= 2;
        		// return res;
                break;
        	} else if (sum + d[pos] < n) {
        		
        		pos += 2;
        		sum += d[pos];
        	} else {
        		res = d[pos+1];
        		d[pos] -= (n-sum);
        		// return res;
                break;
        	}
            
            // printf("%d %d\n", pos, sum);
        }
        printf("d:\n");
        for (int i = 0; i < tot; i++)
            printf("%d ", d[i]);
        printf("\n");
        return res;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */