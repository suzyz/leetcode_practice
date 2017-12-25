// Brutal. O(N^2)
class MyCalendar {
public:
	vector<pair<int,int>> events;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (int i = 0; i < events.size(); ++i)
        {
        	if (max(start,events[i].first) < min(end,events[i].second))
        		return false;
        }

        events.push_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
