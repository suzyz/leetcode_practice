class StockSpanner {
public:
	std::vector<int> p,f;
    StockSpanner() {
        
    }
    
    int next(int price) {
        p.push_back(price);

        f.push_back(1);

        int n = f.size();
        int i = n-2;
        while (i >= 0) {
        	if (p[i] <= price) {
        		f[n-1] += f[i];
        		i -= f[i];
        	} else {
        		break;
        	}
        }

        return f[n-1];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */