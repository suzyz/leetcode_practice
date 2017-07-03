import java.util.*;

class Interval {
    int start;
    int end;
    Interval() { start = 0; end = 0; }
    Interval(int s, int e) { start = s; end = e; }
}

public class p57 {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
       	int n=intervals.size();
       	if(n==0)
       	{
       		intervals.add(newInterval);
       		return intervals;
       	}

       	int l=0,r=n-1,mid=0;
       	while(l<r)
       	{
       		mid=(l+r)>>1;
       		if(intervals.get(mid).start<=newInterval.end)
       			l=mid+1;
       		else
       			r=mid;
       	}
       	if( && newInterval.st>intervals.get(n-1).start)
       	{
       		intervals.add(newInterval);
       		return intervals;
       	}
       	if(l==0)
       	{
       		intervals.insert(0,newInterval);
       		return intervals;
       	}
       	int lastAffected=l-1;

       	l=0; r=n-1;
       	while(l<r)
       	{
       		mid=(l+r)>>1;
       		if(intervals.get(mid).start<=newInterval.start) r=mid;
       		else l=mid+1;
       	}
       	if(l==0)

       	return intervals;
    }
}