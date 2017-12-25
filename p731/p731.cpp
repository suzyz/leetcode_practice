class MyCalendar {
public:
	vector<pair<int,int>> events;
    MyCalendar() {
        
    }
    bool book(int start, int end) {
        for (int i = 0; i < events.size(); ++i)
        	if (max(start,events[i].first) < min(end,events[i].second))
        		return false;

        events.push_back(make_pair(start,end));
        return true;
    }
};

class MyCalendarTwo {
public:
	vector<pair<int,int>> events;

    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
    	MyCalendar my_calenlar;
        for (int i = 0; i < events.size(); ++i)
        	if (max(start,events[i].first) < min(end,events[i].second))
        	{
        		if (my_calenlar.book(max(start,events[i].first), min(end,events[i].second)) == false)
        			return false;
        	}
        	
        events.push_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
