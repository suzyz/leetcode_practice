import java.util.*;

class Interval {
    int start;
    int end;
    Interval() { start = 0; end = 0; }
    Interval(int s, int e) { start = s; end = e; }
}

public class p56_2 {
    public List<Interval> merge(List<Interval> intervals) {
       	List<Interval> ans=new ArrayList<Interval>();

        int n=intervals.size();
        if(n<1) return ans;

        int[] st=new int[n];
        int[] en=new int[n];
        for(int i=0;i<n;i++)
        {
            st[i]=intervals.get(i).start;
            en[i]=intervals.get(i).end;
        }

        Arrays.sort(st);
        Arrays.sort(en);

        int idx=0,i=0;
        while(idx<n)
        {
            while(i<n-1 && st[i+1]<=en[i]) i++;

            ans.add(new Interval(st[idx],en[i]));
            idx=i+1;
            i++;
        }

        return ans;
    }
}
