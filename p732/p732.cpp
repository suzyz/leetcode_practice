class MyCalendarThree {
public:
	map<int, int> timeAxis;

    MyCalendarThree() {
    }
    
    int book(int start, int end) {
        ++timeAxis[start];
        --timeAxis[end];

        int ans = 0, cur = 0;
        for (map<int, int>::iterator it = timeAxis.begin();
        	it != timeAxis.end(); ++it) {

        	cur += it->second;
        	ans = max(ans, cur);
        }

        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */