import java.util.*;

class Interval {
    int start;
    int end;
    Interval() { start = 0; end = 0; }
    Interval(int s, int e) { start = s; end = e; }
}

public class p56 {
    public List<Interval> merge(List<Interval> intervals) {
        intervals.sort((i1, i2) -> Integer.compare(i1.start, i2.start));

       	List<Interval> ans=new ArrayList<Interval>();

        int idx=0,i=0,st=0,en=0;
        while(idx<intervals.size())
        {
        	st=intervals.get(idx).start;
        	en=intervals.get(idx).end;
        	i=idx+1;
        	while(i<intervals.size() && intervals.get(i).start<=en)
        	{
        		en=intervals.get(i).end>en ? intervals.get(i).end:en;
        		i++;
        	}
        	ans.add(new Interval(st,en));
        	idx=i;
        }

        return ans;
    }
}
