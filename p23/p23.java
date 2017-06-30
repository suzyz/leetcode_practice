
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}
 
public class p23 {
    public static void heapAdjust(int cur,int max,int[] h,ListNode[] n)
    {
        int i=cur;
        while((i<<1)<=max)
        {
            int p=i<<1;

            int a=n[h[i]].val<=n[h[p]].val ? i:p;
            if(p<max) a=n[h[a]].val<=n[h[p+1]].val ? a:p+1;

            if(a==i) return;

            int tmp=h[i]; h[i]=h[a]; h[a]=tmp;
            i=a;
        }
    }
    public static ListNode mergeKLists(ListNode[] lists) {
        ListNode ans=null,p=null;
        int k=lists.length;
        int[] h = new int[k+1]; /* min heap */
        ListNode[] n = new ListNode[k+1];

        int idx=0;
        for(int i=0;i<k;i++)
            if(lists[i]!=null)
            {
                idx++;
                h[idx]=idx;
                n[idx]=lists[i];
            } 
        k=idx;

        for(int i=k/2;i>=1;i--)
            heapAdjust(i,k,h,n);

        while(k>0)
        {
            int tmp=h[1];
        	if(ans==null)
        		ans=p=n[tmp];
        	else
        	{
        		p.next=n[tmp];
        		p=p.next;
        	}
        	n[tmp]=n[tmp].next;
            if(n[tmp]==null)
            {
                k--;
                if(k==0) break;
                h[1]=h[k+1];
            }

            heapAdjust(1,k,h,n);
        }
        return ans;
    }
    public static void main(String[] args) {
        ListNode[] lists = new ListNode[3];
        lists[0]=new ListNode(2);
        lists[0].next=new ListNode(6);
        lists[0].next.next=new ListNode(10);
        lists[1]=new ListNode(5);

        ListNode res=mergeKLists(lists);
        while(res!=null)
        {
            System.out.println("val:"+res.val); res=res.next;
        } 
    }
}