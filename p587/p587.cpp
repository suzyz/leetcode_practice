/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:

	struct myCMP
	{
		bool operator() (Point& a, Point& b) {
			int tmp = a.x * b.y - b.x * a.y;
			if (tmp == 0)
				return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
			return tmp > 0;
		}
	} mycmp;

	bool turnRight(Point& a, Point& b, Point& c) { 
		int x1 = b.x - a.x, y1 = b.y - a.y;
		int x2 = c.x - a.x, y2 = c.y - a.y;

		int tmp = x1 * y2 - x2 * y1;
		return tmp < 0;
	}

    vector<Point> outerTrees(vector<Point>& points) {
        int n = points.size();
        if (n < 3)
        	return points;

        int idx = 0;
        for (int i = 1; i < n; ++i)
        	if (points[i].x < points[idx].x)
        		idx = i;
        	else if (points[i].x == points[idx].x && points[i].y < points[idx].y)
        		idx = i;

        Point leftBottom = points[idx];

        for (int i = 0; i < n; ++i) {
        	points[i].x -= leftBottom.x;
        	points[i].y -= leftBottom.y;
	    }   

        sort(points.begin(), points.end(), mycmp);
        
        vector<Point> st;
        st.push_back(points[0]);

        int size = 1;
        for (int i = 1; i < n; ++i) {
        	while (size > 1 && turnRight(st[size-2], st[size-1], points[i])) {
        		--size;
        		st.pop_back();
        	}

        	st.push_back(points[i]);
            ++size;
        }
        
        int lastx = st[size-1].x, lasty = st[size-1].y;
        int dist2 = lastx * lastx + lasty * lasty;
        
        set<pair<int, int>> used;
        for (int i = 0; i < st.size(); ++i) {
            int x = st[i].x, y = st[i].y;
            if (x * lasty == y * lastx)
                used.insert(make_pair(x, y));
        }
        
        for (int i = 0; i < n; ++i) {
            int x = points[i].x, y = points[i].y;
            if (x * lasty == y * lastx && x * x + y * y < dist2 && !used.count(make_pair(x, y))) 
                st.push_back(points[i]);
        }

        for (int i = 0; i < st.size(); ++i) {
        	st[i].x += leftBottom.x;
        	st[i].y += leftBottom.y;
        }

        return st;
    }
};