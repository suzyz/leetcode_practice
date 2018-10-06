// 1. 有重点。

// 2. 直接计算斜率deltaY/deltaX会因为精度不够误判。
//    故同时保存除以公因式之后的deltaX和deltaY

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <unordered_map>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if (n < 3)
            return n;

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            unordered_map<int, unordered_map<int, int> > m;
            int overlap = 0, curMax = 0;

            for (int j = i+1; j < n; ++j)
            {
                int x = points[j].x - points[i].x;
                int y = points[j].y - points[i].y;

                if (x == 0 && y == 0) {
                    ++overlap;
                    continue;
                }

                int gcd = getGcd(x, y);
                if (gcd != 0) {
                    x /= gcd;
                    y /= gcd;
                }

                ++m[x][y];
                curMax = max(curMax, m[x][y]);
            }

            ans = max(ans, overlap + curMax + 1);
        }
        
        return ans;
    }

    int getGcd(int a, int b) {
        if (b == 0)
            return a;

        return getGcd(b, a%b);
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    //[[84,250],[0,0],[1,0],[0,-70],[0,-70],[1,-1],[21,10],[42,90],[-42,-230]]
    Point d[] = {Point(0,0),Point(84,250),Point(1,0),Point(0,-70),
        Point(0,-70),Point(1,-1),Point(21,10),
        Point(42,90),Point(-42,-230),
    };
    
    vector<Point> v(d,d + sizeof(d)/sizeof(int));
    cout << s.maxPoints(v) << endl;
    return 0;
}