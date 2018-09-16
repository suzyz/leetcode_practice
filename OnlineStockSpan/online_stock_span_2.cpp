// Using stack. O(1) time.

class StockSpanner {
public:
    int idx = 0;
	stack<pair<int,int>> st;

    StockSpanner() {
        st.push(make_pair(0, INT_MAX));
    }
    
    int next(int price) {
        idx++;

        while (st.top().second <= price) {
            st.pop();
        }

        int len = idx - st.top().first;
        st.push(make_pair(idx, price));
        return len;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */