class MedianFinder {
public:
	priority_queue<int> lo;
	priority_queue<int,vector<int>,greater<int>> hi;

    MedianFinder() {    
    }
    
    void addNum(int num) {
        if (hi.empty() || num >= hi.top())
        	hi.push(num);
        else
        	lo.push(num);

        balance();
    }
    
    double findMedian() {
        if (hi.size() == lo.size())
        	return 0.5*(hi.top() + lo.top());
        return hi.top();
    }

    void balance()
    {
    	while (hi.size() > lo.size() + 1)
    	{
    		lo.push(hi.top());
    		hi.pop();
    	}

    	while (lo.size() > hi.size())
    	{
			hi.push(lo.top());
    		lo.pop();
    	}
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
